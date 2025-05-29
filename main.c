/*
 * File:   main.c
 * Author: Fumiya Inagi
 *
 * Created on October 16, 2024, 5:14 PM
 */
// �R���t�B�M�����[�V�����̐ݒ�
#pragma config FOSC = INTOSC    // �����I�V���[�^���g�p
#pragma config WDTE = OFF       // �E�H�b�`�h�b�O�^�C�}�𖳌�
#pragma config PWRTE = ON       // �p���[�I�����Z�b�g�^�C�}��L��
#pragma config MCLRE = OFF      // MCLR�[�q��I/O�s���Ƃ��Ďg�p
#pragma config CP = OFF         // �v���O�����������̃R�[�h�ی�𖳌�
#pragma config CPD = OFF        // �f�[�^�������̃R�[�h�ی�𖳌�
#pragma config BOREN = OFF      // �{���e�[�W���Z�b�g����
#pragma config CLKOUTEN = OFF   // CLKOUT�@�\����
#pragma config IESO = OFF       // ����/�O���؂�ւ��@�\����
#pragma config FCMEN = OFF      // �t�F�C���Z�[�t�N���b�N�Ď�����
#pragma config WRT = OFF        // �������ݕی얳��
#pragma config PLLEN = OFF      // PLL�g���@�\�����i�����N���b�N16MHz���ɂ͖����̂܂܁j
#pragma config STVREN = ON      // �X�^�b�N�I�[�o�[�t���[���Z�b�g��L��
#pragma config BORV = LO        // ��d�����Z�b�g�ݒ�
#pragma config LVP = OFF        // ��d���v���O���~���O����

// �w�b�_�t�@�C���̓ǂݍ���
#include <xc.h>

// ���̑��̐ݒ�
#define _XTAL_FREQ 31250  // �����N���b�N��31.25kHz�ɐݒ�

// �v���O�����{��
int main(void) {
    // �I�V���[�^�ݒ�F����16MHz�ɐݒ�
    OSCCON = 0b00010000;

    // RA4���o�̓s���Ƃ��Đݒ�iLED����j
    TRISA4 = 0;    // RA4���o�̓��[�h�ɐݒ�
    // RA0, RA1, RA2, RA3, RA5����̓s���Ƃ��Đݒ�
    TRISA0 = 1;    // RA0����̓��[�h�ɐݒ�
    TRISA1 = 1;    // RA1����̓��[�h�ɐݒ�
    TRISA2 = 1;    // RA2����̓��[�h�ɐݒ�
    TRISA3 = 1;    // RA3����̓��[�h�ɐݒ�
    TRISA5 = 1;    // RA5����̓��[�h�ɐݒ�
    // RA0, RA2, RA3, RA5�ɓ����v���A�b�v��R��L���ɐݒ肵�ARA1�̃v���A�b�v�𖳌��ɐݒ�
    WPUA = 0x3D;   // RA0, RA2, RA3, RA5�Ƀv���A�b�v��R��L���ɐݒ�iRA1�͖����j
    
    // ������Ԃ�RA4��HIGH�iLED�_���j�ɐݒ�
    RA4 = 1; // LED��_����Ԃɐݒ�
    
    while(1) {
        // LED�͏�ɓ_�����Ă��邽�߁ARA4�̏�Ԃ�ύX���Ȃ�
        RA4 = 1;  // RA4�����HIGH�ɐݒ肵��LED��_��
    }
    
    return 0;
}


