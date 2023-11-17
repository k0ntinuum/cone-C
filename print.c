void rgb(int r, int g, int b) {
    printf("\x1b[38;2;%d;%d;%dm",r,g,b);
}
void gray(int h) {
    rgb(h,h,h);
}
void cls() {
    printf( "\x1b[2J");
}
void reverse_text() {
    printf("\x1b[7m");
}
void stop_reverse_text() {
    printf("\x1b[27m");
}
void hide_cursor() {
    printf("\x1b[?25l");
}
void show_cursor() {
    printf("\x1b[?25h");
}

void cursor_to(int r, int c) {
    printf("\x1b[%d;%dH",r,c);
}

void print_symbol(u32 i) {
    //gray(arc4random_uniform(255));
    //rgb(arc4random_uniform(255),arc4random_uniform(255),arc4random_uniform(255));
    //rgb(0,arc4random_uniform(155),0);
    switch (i) {
        case 0 : gray(arc4random_uniform(85));reverse_text();printf("O");stop_reverse_text();break;
        case 1 : gray(arc4random_uniform(175));printf("|");break;
        case 2 : gray(arc4random_uniform(15));printf("\u2588");break; //u2594
        case 3 : printf("3");break;
    }
}
void print_key(const u32 k[N][N]) {
	for (u32 i = 0; i <= N/2 ; i++) {
		for (u32 j = 0; j < N; j++) {
            //if (j == center && (i == N/2 || i == 0) )  rgb(255,0,0);
            if (j  <  i) printf("  ");
            if (j  >=  N - i ) printf("  ");
            if (i <= j && j < N - i) {print_symbol(k[i][j]); printf(" ");}
            //if (j == center && (i == N/2 || i == 0) ) rgb(255,255,255);
        }
		printf("\n");
	}
    printf("\n");
}
void print_pyramid(const u32 k[N][N]) {
	//for (u32 i = 0; i <= N/2 ; i++) {
    for (int i = N/2; i > -1   ; i-- ) {
		for (u32 j = 0; j < N; j++) {
            cursor_to(15 - i, 5 + 2*j);
            //if (j == center && (i == N/2 ) )  rgb(255,0,0);
            //print_symbol(k[i][j]); printf(" ");
            if (j  <  i) printf("  ");
            if (j  >=  N - i ) printf("  ");
            if (i <= j && j < N - i) {print_symbol(k[i][j]); printf(" ");}
            //if (j == center && (i == N/2 ) ) rgb(255,255,255);
        }
		printf("\n");
	}
    printf("\n");
}
void print_pyramid_tight(const u32 k[N][N]) {
	//for (u32 i = 0; i <= N/2 ; i++) {
    for (int i = N/2; i > -1   ; i-- ) {
		for (u32 j = 0; j < N; j++) {
            cursor_to(15 - i, 5 + j);
            //if (j == center && (i == N/2 ) )  rgb(255,0,0);
            //print_symbol(k[i][j]); printf(" ");
            if (j  <  i) printf(" ");
            if (j  >=  N - i ) printf(" ");
            if (i <= j && j < N - i) {print_symbol(k[i][j]); printf("");}
            //if (j == center && (i == N/2 ) ) rgb(255,255,255);
        }
		printf("\n");
	}
    printf("\n");
}

// void print_key(const u32 k[N][N]) {
// 	for (u32 i = 0; i <= N/2; i++) {
// 		for (u32 j = 0; j < N; j++) { 
//             //cursor_to(i+1,2*j+2);
//             if (j == N/2  ) rgb(255,0,0);
//             print_symbol(k[i][j]); printf(" ");
//             if (j == N/2 ) rgb(255,255,255);
//         }
            
// 		printf("\n");
// 	}
//     printf("\n");
// }

void print_text(u32 t[T]) {
	for (u32 i = 0; i < T; i++) print_symbol(t[i]);
}
void print_little_key(u32 k[N]) {   
	for (u32 i = 0; i < N; i++) {
        //if (i == N /2 && N %2 == 0 ) printf("  ");
        //if (i == N /2 + 1 && N %2 == 1 ) printf("  ");
        print_symbol(k[i]); 
        printf(" ");
    }
}

	