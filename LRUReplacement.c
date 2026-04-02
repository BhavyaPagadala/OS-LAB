#include <stdio.h>

int main() {
    int pages[50], frames[10], time[10];
    int n, f, i, j, k, pagefaults = 0;
    int found, min, pos, counter = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize
    for(i = 0; i < f; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    for(i = 0; i < n; i++) {
        found = 0;

        // Check if present
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                counter++;
                time[j] = counter;  // Update recent use
                break;
            }
        }

        if(found == 0) {
            // Check empty frame
            int empty = -1;
            for(j = 0; j < f; j++) {
                if(frames[j] == -1) {
                    empty = j;
                    break;
                }
            }

            if(empty != -1) {
                frames[empty] = pages[i];
                counter++;
                time[empty] = counter;
            } else {
                // Find least recently used
                min = time[0];
                pos = 0;

                for(j = 1; j < f; j++) {
                    if(time[j] < min) {
                        min = time[j];
                        pos = j;
                    }
                }

                frames[pos] = pages[i];
                counter++;
                time[pos] = counter;
            }

            pagefaults++;
        }

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
