// mixcolumn_gate.v
// AES MixColumns를 C 코드의 비트단위 XOR 네트워크 기반으로 구현한 Verilog 모듈

`timescale 1ns / 1ps

module mixcolumn_gate (
    input  [31:0] X, // 32비트 입력 (C의 in[0]~in[3]에 해당)
    output [31:0] Y  // 32비트 출력 (C의 out[0]~out[3]에 해당)
);

    // C 코드의 중간 변수들을 Verilog의 wire로 선언
    // x[i]는 입력 X의 각 비트에 매핑됩니다. (x[i] -> X[31-i])
    wire [92:0] t;
    wire [31:0] y;

    // C 코드의 논리식을 Verilog의 assign 문으로 1:1 변환
    // C의 x[i]는 Verilog의 X[31-i]에 해당합니다.
    assign t[0] = X[31-8] ^ X[31-16];
    assign t[1] = X[31-7] ^ X[31-31];
    assign t[2] = X[31-23] ^ t[0];
    assign y[15] = t[1] ^ t[2];
    assign t[4] = X[31-16] ^ X[31-24];
    assign t[5] = X[31-15] ^ t[4];
    assign y[23] = t[1] ^ t[5];
    assign t[7] = X[31-1] ^ X[31-25];
    assign t[8] = X[31-0] ^ t[0];
    assign y[24] = t[7] ^ t[8];
    assign t[10] = X[31-10] ^ X[31-18];
    assign t[11] = X[31-17] ^ t[10];
    assign y[9] = t[7] ^ t[11];
    assign t[13] = X[31-3] ^ X[31-27];
    assign t[14] = X[31-2] ^ t[13];
    assign y[26] = t[10] ^ t[14];
    assign t[16] = X[31-1] ^ X[31-9];
    assign t[17] = X[31-8] ^ t[16];
    assign y[0] = t[4] ^ t[17];
    assign t[19] = X[31-18] ^ X[31-26];
    assign t[20] = X[31-25] ^ t[19];
    assign y[17] = t[16] ^ t[20];
    assign t[22] = X[31-11] ^ X[31-19];
    assign t[23] = X[31-2] ^ t[19];
    assign y[10] = t[22] ^ t[23];
    assign t[25] = X[31-11] ^ t[10];
    assign t[26] = X[31-3] ^ t[25];
    assign y[2] = X[31-26] ^ t[26];
    assign t[28] = X[31-27] ^ y[10];
    assign y[18] = t[25] ^ t[28];
    assign t[30] = X[31-26] ^ t[16];
    assign t[31] = y[9] ^ t[23];
    assign y[1] = t[30] ^ t[31];
    assign t[33] = X[31-2] ^ t[30];
    assign y[25] = X[31-17] ^ t[33];
    assign t[35] = X[31-17] ^ t[4];
    assign t[36] = X[31-1] ^ t[35];
    assign y[16] = y[24] ^ t[36];
    assign t[38] = X[31-0] ^ t[16];
    assign y[8] = t[36] ^ t[38];
    assign t[40] = X[31-0] ^ X[31-8];
    assign t[41] = X[31-31] ^ t[40];
    assign t[42] = X[31-15] ^ t[41];
    assign y[7] = X[31-23] ^ t[42];
    assign t[44] = y[15] ^ t[41];
    assign y[31] = t[5] ^ t[44];
    assign t[46] = X[31-14] ^ X[31-22];
    assign t[47] = X[31-21] ^ X[31-29];
    assign t[48] = X[31-5] ^ t[46];
    assign y[13] = t[47] ^ t[48];
    assign t[50] = t[1] ^ t[46];
    assign t[51] = X[31-30] ^ t[42];
    assign y[6] = t[50] ^ t[51];
    assign t[53] = X[31-6] ^ X[31-14];
    assign t[54] = t[47] ^ t[53];
    assign y[5] = X[31-13] ^ t[54];
    assign t[56] = y[6] ^ t[53];
    assign y[14] = t[44] ^ t[56];
    assign t[58] = X[31-0] ^ X[31-24];
    assign t[59] = X[31-6] ^ t[50];
    assign y[30] = t[58] ^ t[59];
    assign t[61] = X[31-22] ^ X[31-30];
    assign t[62] = t[44] ^ y[30];
    assign y[22] = t[61] ^ t[62];
    assign t[64] = X[31-5] ^ X[31-29];
    assign t[65] = t[61] ^ t[64];
    assign y[21] = X[31-13] ^ t[65];
    assign t[67] = t[46] ^ t[65];
    assign y[29] = y[5] ^ t[67];
    assign t[69] = X[31-4] ^ X[31-12];
    assign t[70] = X[31-28] ^ t[4];
    assign t[71] = t[47] ^ t[69];
    assign y[20] = t[70] ^ t[71];
    assign t[73] = X[31-20] ^ t[13];
    assign t[74] = X[31-11] ^ t[70];
    assign y[19] = t[73] ^ t[74];
    assign t[76] = t[58] ^ t[64];
    assign t[77] = t[69] ^ t[76];
    assign y[28] = X[31-20] ^ t[77];
    assign t[79] = X[31-12] ^ t[0];
    assign t[80] = X[31-19] ^ t[79];
    assign y[11] = t[73] ^ t[80];
    assign t[82] = t[40] ^ t[69];
    assign t[83] = X[31-28] ^ t[82];
    assign y[3] = t[23] ^ t[83];
    assign t[85] = X[31-3] ^ y[19];
    assign t[86] = y[11] ^ t[85];
    assign y[27] = t[82] ^ t[86];
    assign t[88] = y[28] ^ t[79];
    assign t[89] = X[31-13] ^ t[88];
    assign t[90] = X[31-21] ^ t[89];
    assign y[4] = y[20] ^ t[90];
    assign t[92] = X[31-28] ^ t[90];
    assign y[12] = t[76] ^ t[92];

    // 최종 출력 비트들을 32비트 버스 Y로 결합
    assign Y = y;
    
endmodule