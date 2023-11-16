void copy_key(u32 d[N],u32 s[N]) {
    for (u32 i = 0; i < N; i++) d[i] = s[i];
}
void shift(u32* t, u32 l, u32 s) {
    u32 temp[T];
    for (u32 i = 0; i < l; i++) temp[i] = t[(l + i + s)%l];
    for (u32 i = 0; i < l; i++) t[i] = temp[i];
}

void encode(u32 c[T], u32 p[T], u32 f[N][N], u32 k[N]) {
	//load_f(f,0,k);
	calc(f,k,0);
	for (u32 i = 0 ; i < T ; i++) {
		c[i] = ( apex(f) + p[i] )%B;
		shift(k, N - 1, p[i] + 1);
		calc(f,k,p[i]);
		//load_f(f,p[i],k);
		//spin_key(k, trace(k), c[i] + p[i]);
	}
}
void decode(u32 d[T], u32 c[T], u32 f[N][N], u32 k[N]) {
	calc(f,k,0);
	for (u32 i = 0 ; i < T ; i++) {
		d[i] = (B + c[i] - apex(f))%B;
		shift(k, N - 1, d[i] + 1);
		calc(f,k,d[i]);
		//load_f(f,d[i],k);
		//spin_key(k, trace(k), c[i] + d[i]);
	}
}
void reverse(u32 t[T]) {
    u32 temp[T];
    for (u32 i = 0; i < T; i++) temp[i] = t[i];
    for (u32 i = 0; i < T; i++) t[i] = temp[T - 1 - i];
}

void encrypt(u32 c[T], u32 p[T], u32 f[N][N], u32 k[N]  ) {
	u32 m[N] = {0};
	u32 u[T] = {0};
	u32 v[T] = {0};
	copy_text(v,p);
	for (u32 r = 0 ; r < N ; r++) {
		copy_key(m,k);
		shift(m, N - 1,  r);
		copy_text(u,v);
		encode(v,u,f,m);
		reverse(v);
	}
	copy_text(c,v);
}
void decrypt(u32 d[T], u32 c[T], u32 f[N][N], u32 k[N]) {
	u32 m[N] = {0};
	u32 u[T] = {0};
	u32 v[T] = {0};
	copy_text(v,c);
	for (u32 r = 0 ; r < N ; r++) {
		copy_key(m,k);
		shift(m, N - 1, N - 1 - r);
		copy_text(u,v);
		reverse(u);
		decode(v,u,f,m);	
	}
	copy_text(d,v);
}


