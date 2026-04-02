#include <stdio.h>

int main() {
    int pages[50], frames[10];
    int n, f, i, j, k = 0, pagefaults = 0;
    int found, farthest, index, pos;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames
    for(i = 0; i < f; i++) {
        frames[i] = -1;
    }

    for(i = 0; i < n; i++) {
        found = 0;

        // Check if page already present
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(found == 0) {
            // Check for empty frame
            int empty = -1;
            for(j = 0; j < f; j++) {
                if(frames[j] == -1) {
                    empty = j;
                    break;
                }
            }

            if(empty != -1) {
                frames[empty] = pages[i];
            } else {
                // Optimal logic: find farthest used page
                farthest = -1;
                pos = -1;

                for(j = 0; j < f; j++) {
                    index = -1;

                    for(k = i + 1; k < n; k++) {
                        if(frames[j] == pages[k]) {
                            index = k;
                            break;
                        }
                    }

                    // If page not found in future
                    if(index == -1) {
                        pos = j;
                        break;
                    }

                    // Choose farthest
                    if(index > farthest) {
                        farthest = index;
                        pos = j;
                    }
                }

                frames[pos] = pages[i];
            }

            pagefaults++;
        }

        // Print frames after each step
        printf("After page %d: ", pages[i]);
        for(j = 0; j < f; j++) {
            if(frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("Total Page Faults = %d\n", pagefaults);

    return 0;
}
