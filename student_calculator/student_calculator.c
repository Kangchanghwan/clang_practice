#include <stdio.h>
#include <assert.h>
#include "student_calculator.h"

#define S_MAX_STUDENT_CNT 100
#define S_MAX_SUBJECT_CNT 100

static int s_student_cnt = 0;
static int s_subject_cnt = 0;

static int s_num_matrix[S_MAX_STUDENT_CNT + 1][S_MAX_SUBJECT_CNT + 1] = {0};

static void input_console(void) {
    int i,j;

    for (i = 0; i < s_student_cnt ; i++) {
        for (j = 0; j < s_subject_cnt; j++) {
            scanf(" %d", &s_num_matrix[i][j]);
        }
    }
}

static void print_rst_console(void) {
    int i,j;

    for (i = 0; i < s_student_cnt + 1;  i++) {
        for (j = 0; j < s_subject_cnt + 1; j++) {
            printf("%d ",s_num_matrix[i][j]);
        }
        puts("");
    }
}

static void calc_student_total(const int i, const int j) {
    s_num_matrix[s_student_cnt][j] += s_num_matrix[i][j];
}

static void calc_subject_total(const int i, const int j) {
    s_num_matrix[i][s_subject_cnt] += s_num_matrix[i][j];
}

static void calc_all_total(const int i, const int j) {
    s_num_matrix[s_student_cnt][s_subject_cnt] += s_num_matrix[i][j];
}

static void calc(void) {
    int i,j;

    for (i = 0; i < s_student_cnt;  i++) {
        for (j = 0; j < s_subject_cnt; j++) {
            calc_subject_total(i, j);
            calc_student_total(i, j);
            calc_all_total(i, j);
        }
    }

}

static void set_student_subject_cnt(const int student_cnt, const int subject_cnt){

    assert(student_cnt <= S_MAX_STUDENT_CNT);
    assert(subject_cnt <= S_MAX_SUBJECT_CNT);

    s_student_cnt = student_cnt;
    s_subject_cnt = subject_cnt;
}

void calc_student_subject_total(const int student_cnt, const int subject_cnt) {
    set_student_subject_cnt(student_cnt, subject_cnt);
    input_console();
    calc();
    print_rst_console();
}

