#include <stdio.h>

int main() {
    int pages[30], frames[10];
    int num_pages, num_frames;
    int page_faults = 0, page_hits = 0;
    int i, j, k = 0, found;

 
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
    }

    
    for(i = 0; i < num_pages; i++) {
        found = 0;

        
        for(j = 0; j < num_frames; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                page_hits++;
                break;
            }
        }

        
        if(!found) {
            frames[k] = pages[i];       
            k = (k + 1) % num_frames;   
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
        printf("\n");
    }


    printf("\nTotal Page Faults: %d\n", page_faults);
    printf("Total Page Hits: %d\n", page_hits);

    return 0;
}
