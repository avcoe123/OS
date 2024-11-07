
#include <stdio.h>
int main() {
    int pages[30], frames[10], recent[10];
    int num_pages, num_frames;
    int page_faults = 0, page_hits = 0;
    int i, j, least_recent;

    printf("Enter the number of pages: ");
    scanf("%d", &num_pages);
    printf("Enter the page numbers:\n");
    for(i = 0; i < num_pages; i++) {
        scanf("%d", &pages[i]);
    }

    
    printf("Enter the number of frames: ");
    scanf("%d", &num_frames);

   
    for(i = 0; i < num_frames; i++) {
        frames[i] = -1;
        recent[i] = 0;  
    }

   
    for(i = 0; i < num_pages; i++) {
        int found = 0;

       
        for(j = 0; j < num_frames; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                page_hits++;
                recent[j] = i;
                break;
            }
        }

        if(!found) {
            int empty_frame = -1;

            
            for(j = 0; j < num_frames; j++) {
                if(frames[j] == -1) {
                    empty_frame = j;
                    break;
                }
            }

            if(empty_frame != -1) {
                frames[empty_frame] = pages[i];
                recent[empty_frame] = i;
            } else {
               
                least_recent = 0;
                for(j = 1; j < num_frames; j++) {
                    if(recent[j] < recent[least_recent]) {
                        least_recent = j;
                    }
                }
                frames[least_recent] = pages[i];
                recent[least_recent] = i;
            }
            page_faults++;
        }
        printf("Page %d: ", pages[i]);
        for(j = 0; j < num_frames; j++) {
            if(frames[j] != -1) {
                printf("%d ", frames[j]);
            } else {
                printf("- ");
            }
        }

        if (found) {
            printf("(Hit)");
        } else {
            printf("(Fault)");
        }

        printf("\n");
    }
    printf("\nTotal Page Faults: %d\n", page_faults);
    printf("Total Page Hits: %d\n", page_hits);

    return 0;
}
