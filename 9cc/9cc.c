#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    // MEMO
    // ./9cc 123 とプログラムを実行すると
    // 第一引数は "9cc" (自身のファイル名)
    // 第二引数は "123" (受け付けた引数)となる
    // なのでargcは2、argvは2つの文字列を受け取ることとなる
    if (argc != 2) {
        fprintf(stderr, "引数の個数が正しくありません\n");
        return 1;
    }

    char *p = argv[1];

    printf(".intel_syntax noprefix\n");
    printf(".global main\n");
    printf("main:\n");
    printf("  mov rax, %ld\n", strtol(p, &p, 10));
    // @link https://marycore.jp/prog/c-lang/stdlib-strtol/

    while (*p) {
        if (*p == '+') {
            p++;
            printf("  add rax, %ld\n", strtol(p, &p, 10));
            continue;
        }

        if (*p == '-') {
            p++;
            printf("  sub rax, %ld\n", strtol(p, &p, 10));
            continue;
        }

        fprintf(stderr, "予期しない文字です: '%c'\n", *p);
        return 1;
    }

    printf("  ret\n");
    return 0;
}
