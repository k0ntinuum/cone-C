void shift_row(u32 k[N][N], u32 r, u32 s) {
    u32 temp[T];
    for (u32 i = 0; i < N; i++) temp[i] = k[r][(i + s)%N];
    for (u32 i = 0; i < N; i++) k[r][i] = temp[i];
}
void shift_col(u32 k[N][N], u32 c, u32 s) {
    u32 temp[T];
    for (u32 i = 0; i < N; i++) temp[i] = k[(i + s)%N][c];
    for (u32 i = 0; i < N; i++) k[i][c] = temp[i];
}
void spin_key(u32 k[N][N], u32 d, u32 a) {
	for (u32 i = 0 ; i < N ; i++) {
		switch ((i + d)% 2) {
			case 0 : shift_row(k, i, k[i][i] + a + 1);break;
			case 1 : shift_col(k, i, k[i][i] + a + 1);break;
		}
	}
}
u32 trace(u32 k[N][N]) {
	u32 s = 0;
	for (u32 i = 0; i < N; i++) s += k[i][i];
	return s;
}
void auto_spin(u32 k[N][N], u32 j) {
	for (u32 i = 0 ; i < N ; i++) switch (k[i][j]%2) {
            case 0 : shift_row(k, i, k[j][i] + 1);break;
            case 1 : shift_col(k, i, k[j][i] + 1);break;
    }
}
