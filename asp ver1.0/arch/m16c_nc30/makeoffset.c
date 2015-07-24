/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005,2006 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2008 by Witz Corporation, JAPAN
 * 
 *  上記著作権者は，以下の (1)〜(4) の条件か，Free Software Foundation 
 *  によって公表されている GNU General Public License の Version 2 に記
 *  述されている条件を満たす場合に限り，本ソフトウェア（本ソフトウェア
 *  を改変したものを含む．以下同じ）を使用・複製・改変・再配布（以下，
 *  利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，その適用可能性も
 *  含めて，いかなる保証も行わない．また，本ソフトウェアの利用により直
 *  接的または間接的に生じたいかなる損害に関しても，その責任を負わない．
 * 
 */


/*
 *	offset.inc (もしくは offset.h) について
 *
 *	  offset.inc は構造体の特定の要素が構造体の先頭から何バイト目に
 *	存在するかということや, 特定のビットフィールドが先頭から
 *	何バイト先の何ビット目に存在するか, という情報を
 *	アセンブリ言語ファイルに与えるために存在している.
 *
 *	  offset.inc ファイルの中身は, 単なるシンボル定義ファイルである.
 *	シンボルといっても定義するシンボルの名称にはパターンがあり,
 *	大きく分けて次の3種類に分類できる.
 *
 *	<構造体名>_<要素名>	(例) TCB_sp, TCB_pc, TCB_enatex など
 *	<構造体名>_<要素名>_bit	(例) TCB_enatex_bit など
 *	<構造体名>_<要素名>_mask (例) TCB_enatex_mask など
 *
 *	(例)
 *		TCB_texptn		.equ	14
 *		TCB_sp			.equ	20
 *		TCB_pc			.equ	24
 *		TCB_enatex		.equ	13
 *		TCB_enatex_bit		.equ	 6
 *		TCB_enatex_mask		.equ	0040H
 *
 *	  一番はじめは特定の要素が構造体の先頭から何バイト先にあるか
 *	ということを示す数値につけるラベルの名称.
 *	  二番目は特定のビットフィールド中のビットが, 下位から数えて
 *	何ビット目にあるかということを示す数値につけるラベルの名称. 
 *	0から始まる数値で表現する. 最も下位のビットは第0ビットである.
 *	  三番目は先ほどの <構造体名>_<要素名>_bit とも関連するが,
 *	特定のビットフィールド中のビットのマスク値の名称.
 *	_bit と *_mask の値の間には次の関係がある.
 *		(*_mask) == (1 << *_bit)
 * *	(例) TCB_enatex_bit が 6 の時, TCB_enatex_mask は 40H
 *
 *	  ちなみにM16C依存部の実装では, 特定ビットのチェックなどに
 *	ビット命令アドレッシングを使用しているので *_mask というラベルは
 *	使用していない.
 */

/*
 *	offset.inc の作り方(M16Cターゲット依存部向け)
 *
 *	  GNU Cコンパイラを用いているターゲット依存部については,
 *	カーネルのトップディレクトリの下にある util というディレクトリの
 *	下に genoffset という perl スクリプトが用意されているので,
 *	特に手動で offset.h を作成する必要はない.
 *	  genoffset は GNU 開発環境を想定して作成されているので,
 *	生成されるアセンブリ言語疑似命令や生成規則の異なる他の
 *	Cコンパイラにはそのまま適用できない可能性がある.
 *	  そこで, ここではWindows環境 向けの genoffset を用意せず,
 *	作り方をここに記し, 手作業で offset.inc を作成してもらうことと
 *	する. 以下にその方法を示す. なお, この方法はM16Cの開発環境や
 *	命令セットに依存しているため, 他のターゲットを使用している場合は
 *	そのまま適用できない.
 *
 *  1.	makeoffset.c というファイルからCコンパイラを使用して
 *	アセンブリ言語ファイル makeoffset.a30 を生成する.
 *	コンパイルオプションはカーネルコードに与えるものと同じ
 *	ものを与える. 
 *	ルネサス製ツール TM を使用している場合は, プロジェクトエディタの
 *	生成手順ビューから makeoffset.a30 を選び, 右クリックメニューの
 *	｢部分ビルド｣を選択することで生成できる.
 *	もしくはコマンドプロンプトでメイクファイルと同じディレクトリに
 *	移動し, "make -f メイクファイル名 makeoffset.a30" を
 *	実行しても同様の結果が得られる. (メイクファイルはTMが使用して
 *	いるものと同じファイルを指定可能)
 *
 *	2.	先ほどの 1. の作業で得られた, makeoffset.a30 ファイルから
 *	"_____BEGIN_OFF_TCB_tstat"  ではじまる部分を探す.
 *
 *	4箇所あり, それぞれ少しずつ異なるので順に説明する.
 *	(以下, 説明中ではアセンブリ言語ファイルのコメント行は省く)
 *
 * (1)	構造体の先頭からメンバへのオフセット
 *
 *	_____BEGIN_OFF_TCB_tstat:
 *	.word	0000H
 *	.word	0000H
 *	.word	0000H
 *	.word	0000H
 *	.word	0000H
 *	.word	0000H
 *	.word	0000H
 *	.word	0000H
 *	.word	0000H
 *	.word	0000H
 *	.byte	01H
 *	.byte	00H
 *
 *	上記"_____BEGIN_OFF_"の後ろの文字列がoffset.incで定義するシンボル名
 *	となる.
 *	そのシンボルの値は, ビットがたっている箇所までを数えればよい。
 *	word * 10 = 20 なので
 *	TCB_tstat	.equ	20
 *	という行を記述する.
 */

#include "kernel_impl.h"
#include "task.h"

static const TCB	____BEGIN_OFF_TCB_tstat = {
		{ NULL, NULL }, NULL , 1, 0,
		0, 0 , 0 , 0 , NULL , { NULL , NULL }
	};

static const TCB	____BEGIN_OFF_TCB_tinib = {
		{ NULL, NULL }, (TINIB *)1 , 0 , 0,
		0, 0 , 0 , 0 , NULL , { NULL , NULL }
	};

static const TCB	____BEGIN_OFF_TCB_pc = {
		{ NULL, NULL }, NULL, 0, 0,
		0, 0 , 0 , 0 , NULL , { NULL , 1U }
	};
static const TCB	____BEGIN_OFF_TCB_sp = {
		{ NULL, NULL }, NULL, 0, 0,
		0, 0 , 0 , 0 , NULL , { (void *)1 , NULL }
	};

static const TCB	____BEGIN_BIT_TCB_enatex = {
		{ NULL, NULL }, NULL, 0, 0,
		0, 0 , 1 , 0 , NULL , { NULL , NULL }
	};

static const TCB	____BEGIN_OFF_TCB_texptn = {
		{ NULL, NULL }, NULL, 0, 0,
		0 , 0 , 0 , 1 , NULL , { NULL , NULL }
	};

static const TINIB	____BEGIN_OFF_TINIB_exinf = {
		0 , (intptr_t)1 , NULL , 0 , 0 , NULL , 0 , NULL
	};

static const TINIB	____BEGIN_OFF_TINIB_task = {
		0 , NULL , (TASK)1 , 0 , 0 , NULL , 0 , NULL
	};

