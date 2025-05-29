/*
 * File:   main.c
 * Author: Fumiya Inagi
 *
 * Created on October 16, 2024, 5:14 PM
 */
// コンフィギュレーションの設定
#pragma config FOSC = INTOSC    // 内部オシレータを使用
#pragma config WDTE = OFF       // ウォッチドッグタイマを無効
#pragma config PWRTE = ON       // パワーオンリセットタイマを有効
#pragma config MCLRE = OFF      // MCLR端子をI/Oピンとして使用
#pragma config CP = OFF         // プログラムメモリのコード保護を無効
#pragma config CPD = OFF        // データメモリのコード保護を無効
#pragma config BOREN = OFF      // ボルテージリセット無効
#pragma config CLKOUTEN = OFF   // CLKOUT機能無効
#pragma config IESO = OFF       // 内部/外部切り替え機能無効
#pragma config FCMEN = OFF      // フェイルセーフクロック監視無効
#pragma config WRT = OFF        // 書き込み保護無効
#pragma config PLLEN = OFF      // PLL拡張機能無効（内部クロック16MHz時には無効のまま）
#pragma config STVREN = ON      // スタックオーバーフローリセットを有効
#pragma config BORV = LO        // 低電圧リセット設定
#pragma config LVP = OFF        // 低電圧プログラミング無効

// ヘッダファイルの読み込み
#include <xc.h>

// その他の設定
#define _XTAL_FREQ 31250  // 内部クロックを31.25kHzに設定

// プログラム本体
int main(void) {
    // オシレータ設定：内部16MHzに設定
    OSCCON = 0b00010000;

    // RA4を出力ピンとして設定（LED制御）
    TRISA4 = 0;    // RA4を出力モードに設定
    // RA0, RA1, RA2, RA3, RA5を入力ピンとして設定
    TRISA0 = 1;    // RA0を入力モードに設定
    TRISA1 = 1;    // RA1を入力モードに設定
    TRISA2 = 1;    // RA2を入力モードに設定
    TRISA3 = 1;    // RA3を入力モードに設定
    TRISA5 = 1;    // RA5を入力モードに設定
    // RA0, RA2, RA3, RA5に内部プルアップ抵抗を有効に設定し、RA1のプルアップを無効に設定
    WPUA = 0x3D;   // RA0, RA2, RA3, RA5にプルアップ抵抗を有効に設定（RA1は無効）
    
    // 初期状態でRA4をHIGH（LED点灯）に設定
    RA4 = 1; // LEDを点灯状態に設定
    
    while(1) {
        // LEDは常に点灯しているため、RA4の状態を変更しない
        RA4 = 1;  // RA4を常にHIGHに設定してLEDを点灯
    }
    
    return 0;
}


