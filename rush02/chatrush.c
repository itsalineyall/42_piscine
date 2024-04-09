#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

const char *ONES[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const char *TENS[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

char *to_words(int n) {
    if (n < 0) {
        return NULL;
    }
    if (n < 20) {
        return strdup(ONES[n]);
    }
    if (n < 100) {
        char *result = malloc(strlen(TENS[n/10]) + strlen(ONES[n%10]) + 1);
        sprintf(result, "%s %s", TENS[n/10], ONES[n%10]);
        return result;
    }
    if (n < 1000) {
        char *result = malloc(strlen(ONES[n/100]) + strlen("hundred") + (n%100 == 0 ? 0 : strlen(" and ")) + strlen(to_words(n%100)) + 1);
        sprintf(result, "%s hundred%s%s", ONES[n/100], n%100 == 0 ? "" : " and ", to_words(n%100));
        return result;
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    char *words = to_words(n);
    if (words == NULL) {
        printf("Invalid number: %d\n", n);
        return 1;
    }
    int fd = open("output.txt", O_WRONLY|O_CREAT|O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    write(fd, words, strlen(words));
    close(fd);
    printf("%d is %s\n", n, words);
    free(words);
    return 0;
}
