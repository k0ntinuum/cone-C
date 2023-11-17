void shuffle(u32* v, u32 len) {
    u32 j = 0;
    u32 temp = 0;
    for (u32 i = len - 1; i > 0; i -= 1) {
        j = arc4random_uniform(i+1);
        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
}

void check_text_equality(const u32 u[T], const u32 v[T] ) {
	for (u32 i = 0; i < T; i++) if (u[i] != v[i]) printf("inequality found at symbol %d \n",i);
}

void record_difference(u32* x, const u32* y, const u32* z) {
    for (u32 i = 0; i < T; i++) x[i] = (y[i] != z[i]);
}

void copy_text(u32 d[T] , u32 s[T]) {
	for (u32 i = 0; i < T; i++) d[i] = s[i];
}

