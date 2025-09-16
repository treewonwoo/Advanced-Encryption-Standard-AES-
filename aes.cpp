#include <stdint.h>
#include <string.h>
#include <stdio.h>

static uint8_t aes_sbox_gate(uint8_t X) {
    uint8_t x[8]; for (int i = 0; i < 8; i++) x[i] = (X >> i) & 1;  
    uint8_t y[8] = { 0 }, g[64] = { 0 }, r[64] = { 0 }, t[93] = { 0 };
    
    r[5] = x[0]; r[33] = x[0]; t[0] = x[1] ^ x[7]; 
    r[6] = t[0]; r[53] = t[0]; t[1] = x[4] ^ x[7]; 
    r[12] = t[1]; r[59] = t[1]; t[2] = x[2] ^ x[4]; 
    r[14] = t[2]; r[61] = t[2]; t[3] = t[0] ^ t[2]; 
    r[0] = t[3]; r[47] = t[3];  t[4] = x[2] ^ x[7]; 
    r[16] = t[4]; r[63] = t[4]; t[5] = x[5] ^ x[6]; 
    t[6] = x[0] ^ t[5]; r[9] = t[6]; r[37] = t[6]; 
    t[7] = x[4] ^ t[6]; r[4] = t[7]; r[51] = t[7];
    g[2] = r[4] & r[5]; t[8] = x[7] ^ t[6]; r[10] = t[8]; 
    r[57] = t[8]; t[9] = x[1] ^ x[3]; t[10] = t[1] ^ t[9];
    r[1] = t[10]; r[29] = t[10]; g[0] = r[0] & r[1]; 
    t[11] = x[0] ^ t[10]; r[3] = t[11]; r[31] = t[11];
    t[12] = t[5] ^ t[10]; r[17] = t[12]; r[45] = t[12]; g[8] = r[16] & r[17]; t[13] = x[2] ^ x[5]; t[14] = t[9] ^ t[13];
    r[7] = t[14]; r[35] = t[14]; g[3] = r[6] & r[7]; t[15] = t[6] ^ t[14]; r[11] = t[15]; r[39] = t[15];
    g[5] = r[10] & r[11]; t[16] = t[1] ^ t[13]; r[15] = t[16]; r[43] = t[16]; g[7] = r[14] & r[15];
    t[17] = x[2] ^ x[6]; t[18] = t[9] ^ t[17]; r[13] = t[18]; r[41] = t[18]; g[6] = r[12] & r[13];
    t[19] = x[0] ^ x[1]; t[20] = t[5] ^ t[19]; r[8] = t[20]; r[55] = t[20]; g[4] = r[8] & r[9];
    t[21] = t[4] ^ t[20]; r[2] = t[21]; r[49] = t[21]; g[1] = r[2] & r[3];
    t[22] = g[8] ^ g[5]; t[23] = g[7] ^ g[4]; t[24] = g[3] ^ g[6]; t[25] = t[14] ^ t[24]; t[26] = t[13] ^ g[7];
    t[27] = g[1] ^ t[26]; t[28] = t[22] ^ t[23]; t[29] = x[1] ^ t[28]; r[23] = t[29]; t[30] = t[0] ^ t[23];
    t[31] = t[25] ^ t[30]; r[19] = t[31]; t[32] = t[29] ^ t[31]; r[24] = t[32]; t[33] = t[4] ^ g[8];
    t[34] = g[2] ^ t[33]; t[35] = t[27] ^ t[34]; r[20] = t[35]; t[36] = g[0] ^ t[12]; t[37] = g[6] ^ t[36];
    t[38] = t[27] ^ t[37]; r[18] = t[38]; g[9] = r[18] & r[19]; t[39] = t[32] ^ g[9]; r[21] = t[39];
    g[10] = r[20] & r[21]; t[40] = t[34] ^ t[37]; t[41] = g[9] ^ t[40]; r[22] = t[41]; g[11] = r[22] & r[23];
    t[42] = g[9] ^ g[11]; r[25] = t[42]; g[12] = r[24] & r[25]; t[43] = g[10] ^ t[40]; r[26] = t[43];
    r[38] = t[43]; r[56] = t[43]; g[19] = r[38] & r[39]; g[28] = r[56] & r[57]; t[44] = t[39] ^ g[12]; r[27] = t[44];
    g[13] = r[26] & r[27]; t[45] = t[31] ^ g[12]; r[28] = t[45]; r[46] = t[45]; g[14] = r[28] & r[29]; g[23] = r[46] & r[47];
    t[46] = t[32] ^ g[11]; r[32] = t[46]; r[50] = t[46]; g[16] = r[32] & r[33]; g[25] = r[50] & r[51]; t[47] = t[35] ^ g[13];
    r[36] = t[47]; r[54] = t[47]; g[18] = r[36] & r[37]; g[27] = r[54] & r[55]; t[48] = t[43] ^ t[46]; r[40] = t[48];
    r[58] = t[48]; g[20] = r[40] & r[41]; g[29] = r[58] & r[59]; t[49] = t[38] ^ g[10]; t[50] = g[13] ^ t[49];
    r[34] = t[50]; r[52] = t[50]; g[17] = r[34] & r[35]; g[26] = r[52] & r[53]; t[51] = t[45] ^ t[49]; t[52] = g[13] ^ t[51];
    r[42] = t[52]; r[60] = t[52]; g[21] = r[42] & r[43]; g[30] = r[60] & r[61]; t[53] = t[29] ^ g[11];
    t[54] = g[12] ^ t[53]; r[30] = t[54]; r[48] = t[54]; g[15] = r[30] & r[31]; g[24] = r[48] & r[49]; t[55] = g[29] ^ g[30];
    t[56] = g[23] ^ g[24]; t[57] = t[55] ^ t[56]; t[58] = t[35] ^ t[54]; t[59] = g[13] ^ t[58]; r[44] = t[59]; r[62] = t[59];
    g[22] = r[44] & r[45]; g[31] = r[62] & r[63]; t[60] = g[20] ^ g[21]; t[61] = g[18] ^ g[17]; t[62] = g[14] ^ g[15];
    t[63] = g[19] ^ g[18]; t[64] = g[27] ^ g[26]; t[65] = t[55] ^ t[64]; t[66] = g[14] ^ g[16]; t[67] = t[60] ^ t[62];
    t[68] = t[57] ^ t[67]; y[6] = t[68] ^ 1; t[69] = t[61] ^ t[62]; t[70] = t[57] ^ t[69]; y[4] = t[70];
    t[71] = t[60] ^ t[61]; t[72] = t[57] ^ t[71]; y[7] = t[72]; t[73] = g[16] ^ g[15]; t[74] = t[63] ^ t[73];
    t[75] = t[57] ^ t[74]; y[3] = t[75]; t[76] = g[21] ^ g[22]; t[77] = t[63] ^ t[76]; t[78] = t[65] ^ t[77]; y[1] = t[78] ^ 1;
    t[79] = g[19] ^ t[66]; t[80] = g[17] ^ t[79]; t[81] = t[65] ^ t[80]; y[0] = t[81] ^ 1; t[82] = g[28] ^ g[29]; t[83] = g[26] ^ t[82];
    t[84] = t[76] ^ t[83]; t[85] = g[31] ^ t[66]; t[86] = t[60] ^ t[85]; t[87] = t[84] ^ t[86]; y[5] = t[87] ^ 1; t[88] = g[25] ^ g[24];
    t[89] = t[66] ^ t[88]; t[90] = g[30] ^ t[89]; t[91] = t[61] ^ t[90]; t[92] = t[84] ^ t[91]; y[2] = t[92];

    return (uint8_t)((y[7] << 7) | (y[6] << 6) | (y[5] << 5) | (y[4] << 4) | (y[3] << 3) | (y[2] << 2) | (y[1] << 1) | (y[0] << 0));
}

static inline uint8_t SBOX(uint8_t x) { return aes_sbox_gate(x); }

static void sub_bytes(uint8_t state[16]) {
    for (int i = 0; i < 16; ++i) {
        state[i] = aes_sbox_gate(state[i]);
    }
}

static void mixcolumn_gate(const uint8_t in[4], uint8_t out[4]) {
	// 입력                  // 임시 변수             // 출력
    uint8_t x[32] = { 0 };  uint8_t t[93] = { 0 };  uint8_t y[32] = { 0 };
	// 입력 바이트를 비트 단위로 분해
    for (int i = 0; i < 8; i++) {
        int msb = 7 - i;
        x[i] = (in[0] >> msb) & 1; // in[0] -> x[0-7]
        x[i + 8] = (in[1] >> msb) & 1; // in[1] -> x[8-15]
        x[i + 16] = (in[2] >> msb) & 1; // in[2] -> x[16-23]
        x[i + 24] = (in[3] >> msb) & 1; // in[3] -> x[24-31]
    }
    // 연산 수행
    t[0] = x[8] ^ x[16];
    t[1] = x[7] ^ x[31];
    t[2] = x[23] ^ t[0];
    y[15] = t[1] ^ t[2];
    t[4] = x[16] ^ x[24];
    t[5] = x[15] ^ t[4];
    y[23] = t[1] ^ t[5];
    t[7] = x[1] ^ x[25];
    t[8] = x[0] ^ t[0];
    y[24] = t[7] ^ t[8];
    t[10] = x[10] ^ x[18];
    t[11] = x[17] ^ t[10];
    y[9] = t[7] ^ t[11];
    t[13] = x[3] ^ x[27];
    t[14] = x[2] ^ t[13];
    y[26] = t[10] ^ t[14];
    t[16] = x[1] ^ x[9];
    t[17] = x[8] ^ t[16];
    y[0] = t[4] ^ t[17];
    t[19] = x[18] ^ x[26];
    t[20] = x[25] ^ t[19];
    y[17] = t[16] ^ t[20];
    t[22] = x[11] ^ x[19];
    t[23] = x[2] ^ t[19];
    y[10] = t[22] ^ t[23];
    t[25] = x[11] ^ t[10];
    t[26] = x[3] ^ t[25];
    y[2] = x[26] ^ t[26];
    t[28] = x[27] ^ y[10];
    y[18] = t[25] ^ t[28];
    t[30] = x[26] ^ t[16];
    t[31] = y[9] ^ t[23];
    y[1] = t[30] ^ t[31];
    t[33] = x[2] ^ t[30];
    y[25] = x[17] ^ t[33];
    t[35] = x[17] ^ t[4];
    t[36] = x[1] ^ t[35];
    y[16] = y[24] ^ t[36];
    t[38] = x[0] ^ t[16];
    y[8] = t[36] ^ t[38];
    t[40] = x[0] ^ x[8];        
    t[41] = x[31] ^ t[40];
    t[42] = x[15] ^ t[41];
    y[7] = x[23] ^ t[42];
    t[44] = y[15] ^ t[41];
    y[31] = t[5] ^ t[44];
    t[46] = x[14] ^ x[22];
    t[47] = x[21] ^ x[29];
    t[48] = x[5] ^ t[46];
    y[13] = t[47] ^ t[48];
    t[50] = t[1] ^ t[46];
    t[51] = x[30] ^ t[42];
    y[6] = t[50] ^ t[51];
    t[53] = x[6] ^ x[14];
    t[54] = t[47] ^ t[53];
    y[5] = x[13] ^ t[54];
    t[56] = y[6] ^ t[53];
    y[14] = t[44] ^ t[56];
    t[58] = x[0] ^ x[24];
    t[59] = x[6] ^ t[50];
    y[30] = t[58] ^ t[59];
    t[61] = x[22] ^ x[30];
    t[62] = t[44] ^ y[30];
    y[22] = t[61] ^ t[62];
    t[64] = x[5] ^ x[29];
    t[65] = t[61] ^ t[64];
    y[21] = x[13] ^ t[65];
    t[67] = t[46] ^ t[65];
    y[29] = y[5] ^ t[67];
    t[69] = x[4] ^ x[12];
    t[70] = x[28] ^ t[4];
    t[71] = t[47] ^ t[69];
    y[20] = t[70] ^ t[71];
    t[73] = x[20] ^ t[13];
    t[74] = x[11] ^ t[70];
    y[19] = t[73] ^ t[74];
    t[76] = t[58] ^ t[64];
    t[77] = t[69] ^ t[76];
    y[28] = x[20] ^ t[77];
    t[79] = x[12] ^ t[0];
    t[80] = x[19] ^ t[79];
    y[11] = t[73] ^ t[80];
    t[82] = t[40] ^ t[69];
    t[83] = t[28] ^ t[82];
    y[3] = t[23] ^ t[83];
    t[85] = x[3] ^ y[19];
    t[86] = y[11] ^ t[85];
    y[27] = t[82] ^ t[86];
    t[88] = y[28] ^ t[79];
    t[89] = x[13] ^ t[88];
    t[90] = x[21] ^ t[89];
    y[4] = y[20] ^ t[90];
    t[92] = x[28] ^ t[90];
    y[12] = t[76] ^ t[92];


    // 출력

    out[0] = out[1] = out[2] = out[3] = 0;
    for (int i = 0; i < 8; i++) {
        int msb = 7 - i;
        out[0] |= (y[i] & 1) << msb;      // y[0-7] -> out[0]
        out[1] |= (y[i + 8] & 1) << msb;  // y[8-15] -> out[1]
        out[2] |= (y[i + 16] & 1) << msb; // y[16-23] -> out[2]
        out[3] |= (y[i + 24] & 1) << msb; // y[24-31] -> out[3]
    }
}

static void mix_columns(uint8_t state[16]) {
    uint8_t col_in[4], col_out[4];
    // 4개의 열 각각에 MixColumns 
    for (int i = 0; i < 4; ++i) {
        col_in[0] = state[i * 4 + 0];
        col_in[1] = state[i * 4 + 1];
        col_in[2] = state[i * 4 + 2];
        col_in[3] = state[i * 4 + 3];

        mixcolumn_gate(col_in, col_out);

        state[i * 4 + 0] = col_out[0];
        state[i * 4 + 1] = col_out[1];
        state[i * 4 + 2] = col_out[2];
        state[i * 4 + 3] = col_out[3];
    }
}

static void shift_rows(uint8_t s[16]) {
    uint8_t t;
    t = s[1];  s[1] = s[5];  s[5] = s[9];  s[9] = s[13]; s[13] = t;
    t = s[2];  s[2] = s[10]; s[10] = t;  t = s[6]; s[6] = s[14]; s[14] = t;
    t = s[3];  s[3] = s[15]; s[15] = s[11]; s[11] = s[7]; s[7] = t;
}

static void add_round_key(uint8_t s[16], const uint8_t* rk) {
    for (int i = 0; i < 16; ++i) s[i] ^= rk[i];
}

static const uint8_t Rcon[255] = { 
    0x00,0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x1B,0x36,
};

static void key_expansion(const uint8_t* key, int keylen, uint8_t* round_keys, int* Nr_out) {
    int Nk = keylen / 32;
    int Nb = 4;
    int Nr = Nk + 6;
    *Nr_out = Nr;
    int words = Nb * (Nr + 1);
    memcpy(round_keys, key, Nk * 4);
    uint8_t temp[4];
    for (int i = Nk; i < words; ++i) {
        memcpy(temp, &round_keys[4 * (i - 1)], 4);
        if (i % Nk == 0) {
            uint8_t t0 = temp[0]; temp[0] = temp[1]; temp[1] = temp[2]; temp[2] = temp[3]; temp[3] = t0;
            temp[0] = SBOX(temp[0]); temp[1] = SBOX(temp[1]); temp[2] = SBOX(temp[2]); temp[3] = SBOX(temp[3]);
            temp[0] ^= Rcon[i / Nk];
        }
        else if (Nk > 6 && i % Nk == 4) {
            temp[0] = SBOX(temp[0]); temp[1] = SBOX(temp[1]); temp[2] = SBOX(temp[2]); temp[3] = SBOX(temp[3]);
        }
        round_keys[4 * i + 0] = round_keys[4 * (i - Nk) + 0] ^ temp[0];
        round_keys[4 * i + 1] = round_keys[4 * (i - Nk) + 1] ^ temp[1];
        round_keys[4 * i + 2] = round_keys[4 * (i - Nk) + 2] ^ temp[2];
        round_keys[4 * i + 3] = round_keys[4 * (i - Nk) + 3] ^ temp[3];
    }
}

void print_round_keys(const uint8_t* round_keys, int Nr) {
    printf("--- AES Key Expansion Result ---\n");
    for (int r = 0; r <= Nr; ++r) {
        printf("Round %2d Key: ", r);
        for (int i = 0; i < 16; ++i) {
            printf("%02x", round_keys[r * 16 + i]);
        }
        printf("\n");
    }
    printf("------------------------------\n\n");
}

void aes_encryption(const uint8_t key[], int keylen, const uint8_t in[16], uint8_t out[16]) {

    uint8_t state[16];
    memcpy(state, in, 16);
    uint8_t rk[240];
    int Nr;

    key_expansion(key, keylen, rk, &Nr);
    printf("--- AES Encryption ---\n");
    printf(" PT: "); for (int i = 0; i < 16; i++) printf("%02x", state[i]); putchar('\n');

    add_round_key(state, rk); 

    for (int r = 1; r < Nr; ++r) {
        sub_bytes(state);
		//printf("After SubBytes: "); for (int i = 0; i < 16; i++) printf("%02x", state[i]); putchar('\n');
        shift_rows(state);
		//printf("After ShiftRows: "); for (int i = 0; i < 16; i++) printf("%02x", state[i]); putchar('\n');
        mix_columns(state);
		//printf("After MixColumns: "); for (int i = 0; i < 16; i++) printf("%02x", state[i]); putchar('\n');
        add_round_key(state, rk + 16 * r);
        //printf("After Round %d: ", r);
        //for (int i = 0; i < 16; i++) printf("%02x", state[i]);
        //putchar('\n');

    }

    sub_bytes(state);
    shift_rows(state);
    add_round_key(state, rk + 16 * Nr);
    printf(" CT : "); for (int i = 0; i < 16; i++) printf("%02x", state[i]); putchar('\n');
    memcpy(out, state, 16);
}

static void hex(const uint8_t* b, int n) { for (int i = 0;i < n;i++) printf("%02x", b[i]); putchar('\n'); }

int main(void) {
    uint8_t key[16] = { 0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f };
    uint8_t pt[16] = { 0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xaa,0xbb,0xcc,0xdd,0xee,0xff };
    uint8_t ct[16];
    aes_encryption(key, 128, pt, ct);    
    return 0;
}
