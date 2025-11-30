#include <stdio.h>     
#include <stdlib.h>     
#include <unistd.h>  
#include <sys/wait.h>
#include <sys/syscall.h>

int main(void) {
    int parent_pid = getpid();
    printf("parent pid: %d\n", parent_pid);
    printf("parent enables pcbcopylog...\n");
    
    syscall(550, 1);
  
    printf("parent (pid: %d) forks...\n", parent_pid);
    int child_A = fork();

    if(child_A == 0){
        parent_pid = getpid();
        printf("child A pid: %d\n", parent_pid);
        printf("child A (pid: %d) forks...\n", parent_pid);
        int child_B = fork();

        if(child_B == 0){
            parent_pid = getpid();
            printf("child B pid: %d\n", parent_pid);
            printf("child B (pid: %d) forks...\n", parent_pid);
            int child_C = fork();

            if(child_C == 0){
                parent_pid = getpid();
                printf("child C pid: %d\n", parent_pid);
                printf("child C disables pcbcopylog...\n");
                
                // Disable logging
                pcbcopylog(0);
                
                printf("child C (pid: %d) forks...\n", parent_pid);
                int child_D = fork();

                if(child_D == 0){
                    parent_pid = getpid();
                    printf("child D pid: %d\n", parent_pid);
                    printf("child D (pid: %d) forks...\n", parent_pid);
                    int child_E = fork();

                    if(child_E == 0){
                        parent_pid = getpid();
                        printf("child E pid: %d\n", parent_pid);
                        printf("child E (pid: %d) exits...\n", parent_pid);
                        exit(0);
                    }
                    printf("child D (pid: %d) waits...\n", parent_pid);
                    wait(NULL);
                    printf("child D (pid: %d) exits...\n", parent_pid);
                    exit(0);
                }
                printf("child C (pid: %d) waits...\n", parent_pid);
                wait(NULL);
                printf("child C (pid: %d) exits...\n", parent_pid);
                exit(0);
            }
            printf("child B (pid: %d) waits...\n", parent_pid);
            wait(NULL);
            printf("child B (pid: %d) exits...\n", parent_pid);
            exit(0);
        }
        printf("child A (pid: %d) waits...\n", parent_pid);
        wait(NULL);
        printf("child A (pid: %d) exits...\n", parent_pid);
        exit(0);
    }
    printf("parent (pid: %d) waits...\n", parent_pid);
    wait(NULL);
    printf("parent (pid: %d) exits...\n", parent_pid);
    exit(0);
}