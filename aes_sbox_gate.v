// aes_sbox_gate.v
// AES S-Box를 C 코드의 논리 게이트 연산 기반으로 구현한 Verilog 모듈

`timescale 1ns / 1ps

module aes_sbox_gate (
    input  [7:0] X, // 8비트 입력 값
    output [7:0] Y  // 8비트 S-Box 출력 값
);

    // C 코드의 중간 변수들을 Verilog의 wire로 선언
    wire [92:0] t;
    wire [63:0] g;
    wire [63:0] r;
    wire [7:0]  y;

    // C 코드의 논리식을 Verilog의 assign 문으로 1:1 변환
    // C의 x[i]는 Verilog의 X[i]에 해당합니다.
    assign r[5] = X[0]; assign r[33] = X[0]; assign t[0] = X[1] ^ X[7]; assign r[6] = t[0]; assign r[53] = t[0];
    assign t[1] = X[4] ^ X[7]; assign r[12] = t[1]; assign r[59] = t[1]; assign t[2] = X[2] ^ X[4]; assign r[14] = t[2]; assign r[61] = t[2];
    assign t[3] = t[0] ^ t[2]; assign r[0] = t[3]; assign r[47] = t[3]; assign t[4] = X[2] ^ X[7]; assign r[16] = t[4]; assign r[63] = t[4];
    assign t[5] = X[5] ^ X[6]; assign t[6] = X[0] ^ t[5]; assign r[9] = t[6]; assign r[37] = t[6]; assign t[7] = X[4] ^ t[6]; assign r[4] = t[7]; assign r[51] = t[7];
    assign g[2] = r[4] & r[5]; assign t[8] = X[7] ^ t[6]; assign r[10] = t[8]; assign r[57] = t[8]; assign t[9] = X[1] ^ X[3]; assign t[10] = t[1] ^ t[9];
    assign r[1] = t[10]; assign r[29] = t[10]; assign g[0] = r[0] & r[1]; assign t[11] = X[0] ^ t[10]; assign r[3] = t[11]; assign r[31] = t[11];
    assign t[12] = t[5] ^ t[10]; assign r[17] = t[12]; assign r[45] = t[12]; assign g[8] = r[16] & r[17]; assign t[13] = X[2] ^ X[5]; assign t[14] = t[9] ^ t[13];
    assign r[7] = t[14]; assign r[35] = t[14]; assign g[3] = r[6] & r[7]; assign t[15] = t[6] ^ t[14]; assign r[11] = t[15]; assign r[39] = t[15];
    assign g[5] = r[10] & r[11]; assign t[16] = t[1] ^ t[13]; assign r[15] = t[16]; assign r[43] = t[16]; assign g[7] = r[14] & r[15];
    assign t[17] = X[2] ^ X[6]; assign t[18] = t[9] ^ t[17]; assign r[13] = t[18]; assign r[41] = t[18]; assign g[6] = r[12] & r[13];
    assign t[19] = X[0] ^ X[1]; assign t[20] = t[5] ^ t[19]; assign r[8] = t[20]; assign r[55] = t[20]; assign g[4] = r[8] & r[9];
    assign t[21] = t[4] ^ t[20]; assign r[2] = t[21]; assign r[49] = t[21]; assign g[1] = r[2] & r[3];
    assign t[22] = g[8] ^ g[5]; assign t[23] = g[7] ^ g[4]; assign t[24] = g[3] ^ g[6]; assign t[25] = t[14] ^ t[24]; assign t[26] = t[13] ^ g[7];
    assign t[27] = g[1] ^ t[26]; assign t[28] = t[22] ^ t[23]; assign t[29] = X[1] ^ t[28]; assign r[23] = t[29]; assign t[30] = t[0] ^ t[23];
    assign t[31] = t[25] ^ t[30]; assign r[19] = t[31]; assign t[32] = t[29] ^ t[31]; assign r[24] = t[32]; assign t[33] = t[4] ^ g[8];
    assign t[34] = g[2] ^ t[33]; assign t[35] = t[27] ^ t[34]; assign r[20] = t[35]; assign t[36] = g[0] ^ t[12]; assign t[37] = g[6] ^ t[36];
    assign t[38] = t[27] ^ t[37]; assign r[18] = t[38]; assign g[9] = r[18] & r[19]; assign t[39] = t[32] ^ g[9]; assign r[21] = t[39];
    assign g[10] = r[20] & r[21]; assign t[40] = t[34] ^ t[37]; assign t[41] = g[9] ^ t[40]; assign r[22] = t[41]; assign g[11] = r[22] & r[23];
    assign t[42] = g[9] ^ g[11]; assign r[25] = t[42]; assign g[12] = r[24] & r[25]; assign t[43] = g[10] ^ t[40]; assign r[26] = t[43];
    assign r[38] = t[43]; assign r[56] = t[43]; assign g[19] = r[38] & r[39]; assign g[28] = r[56] & r[57]; assign t[44] = t[39] ^ g[12]; assign r[27] = t[44];
    assign g[13] = r[26] & r[27]; assign t[45] = t[31] ^ g[12]; assign r[28] = t[45]; assign r[46] = t[45]; assign g[14] = r[28] & r[29]; assign g[23] = r[46] & r[47];
    assign t[46] = t[32] ^ g[11]; assign r[32] = t[46]; assign r[50] = t[46]; assign g[16] = r[32] & r[33]; assign g[25] = r[50] & r[51]; assign t[47] = t[35] ^ g[13];
    assign r[36] = t[47]; assign r[54] = t[47]; assign g[18] = r[36] & r[37]; assign g[27] = r[54] & r[55]; assign t[48] = t[40] ^ t[46]; assign r[40] = t[48];
    assign r[58] = t[48]; assign g[20] = r[40] & r[41]; assign g[29] = r[58] & r[59]; assign t[49] = t[38] ^ g[10]; assign t[50] = g[13] ^ t[49];
    assign r[34] = t[50]; assign r[52] = t[50]; assign g[17] = r[34] & r[35]; assign g[26] = r[52] & r[53]; assign t[51] = t[45] ^ t[49]; assign t[52] = g[13] ^ t[51];
    assign r[42] = t[52]; assign r[60] = t[52]; assign g[21] = r[42] & r[43]; assign g[30] = r[60] & r[61]; assign t[53] = t[29] ^ g[11];
    assign t[54] = g[12] ^ t[53]; assign r[30] = t[54]; assign r[48] = t[54]; assign g[15] = r[30] & r[31]; assign g[24] = r[48] & r[49]; assign t[55] = g[29] ^ g[30];
    assign t[56] = g[23] ^ g[24]; assign t[57] = t[55] ^ t[56]; assign t[58] = t[35] ^ t[54]; assign t[59] = g[13] ^ t[58]; assign r[44] = t[59]; assign r[62] = t[59];
    assign g[22] = r[44] & r[45]; assign g[31] = r[62] & r[63]; assign t[60] = g[20] ^ g[21]; assign t[61] = g[18] ^ g[17]; assign t[62] = g[14] ^ g[15];
    assign t[63] = g[19] ^ g[18]; assign t[64] = g[27] ^ g[26]; assign t[65] = t[55] ^ t[64]; assign t[66] = g[14] ^ g[16]; assign t[67] = t[60] ^ t[62];
    assign t[68] = t[57] ^ t[67]; assign y[6] = t[68] ^ 1'b1; assign t[69] = t[61] ^ t[62]; assign t[70] = t[57] ^ t[69]; assign y[4] = t[70];
    assign t[71] = t[60] ^ t[61]; assign t[72] = t[57] ^ t[71]; assign y[7] = t[72]; assign t[73] = g[16] ^ g[15]; assign t[74] = t[63] ^ t[73];
    assign t[75] = t[57] ^ t[74]; assign y[3] = t[75]; assign t[76] = g[21] ^ g[22]; assign t[77] = t[63] ^ t[76]; assign t[78] = t[65] ^ t[77]; assign y[1] = t[78] ^ 1'b1;
    assign t[79] = g[19] ^ t[66]; assign t[80] = g[17] ^ t[79]; assign t[81] = t[65] ^ t[80]; assign y[0] = t[81] ^ 1'b1; assign t[82] = g[28] ^ g[29]; assign t[83] = g[26] ^ t[82];
    assign t[84] = t[76] ^ t[83]; assign t[85] = g[31] ^ t[66]; assign t[86] = t[60] ^ t[85]; assign t[87] = t[84] ^ t[86]; assign y[5] = t[87] ^ 1'b1; assign t[88] = g[25] ^ g[24];
    assign t[89] = t[66] ^ t[88]; assign t[90] = g[30] ^ t[89]; assign t[91] = t[61] ^ t[90]; assign t[92] = t[84] ^ t[91]; assign y[2] = t[92];


    // {MSB, ..., LSB}
    assign Y = {y[7], y[6], y[5], y[4], y[3], y[2], y[1], y[0]};

endmodule