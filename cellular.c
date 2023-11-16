
int u32_pow(u32 x, u32 b) {
	u32 s = 1;
	for (u32 j = 0; j < x; j++) {
		s *= b;
	}
	return s;
}
int safe_col(int x) {
	if (x < 0) return x + N;
	if (x > N - 1) return x - N;
	return x;
}
int code(u32 r, u32 c, u32 f[N][N], u32 k[N]) {
	int sum = 0;
	int start = c - N/2;
	for (int j = 0; j < N; j++) {
		sum += u32_pow(j,B)*f[r-1][safe_col( start + j)];
	}
	return sum;
}
void load_f(u32 f[N][N], u32 p, u32 k[N]) {
    for (int i = 0; i < N/2 ; i++ ) f[0][i] = k[i];
    for (int i = N/2 + 1; i < N ; i++ ) f[0][i] = k[i-1];
    f[0][N/2] = p;
}
void compute_next_row(u32 d[N], u32 s[N], u32 k[N]) {
    int sum, start;
    for (int c = 0; c < N; c++) {
        sum = 0;start = c - H/2;
        for (int j = 0; j < H; j++) sum += u32_pow(j,B)*s[safe_col( start + j)];
        d[c] = k[sum];
	}
}
void calc(u32 f[N][N], u32 k[N], u32 v) {
    //for (int i = 0; i < N ; i++ ) f[0][i] = k[i];
    load_f(f,v,k);
    for (int i = 1; i < N/2 + 1 ; i++) compute_next_row(f[i],f[i-1],k);
}

u32 apex(u32 f[N][N]) {
    return f[N/2][center];
}