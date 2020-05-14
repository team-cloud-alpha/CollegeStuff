/** SY-CSE : 2019-20
  * OS Assignment 6
  * Demand Paging (Page Replacement Algorithms)
  **/

#include<stdio.h>

// Display current status of page buffer
void displayPages(short* buffer, size_t n) {
	printf("[ ");
	for(size_t k=0;k<n;k++)
		if(buffer[k]!=-1)
			printf("%hi ",buffer[k]);
		else
			printf("_ ");
	printf("]\n");
}

// FIFO replacement algorithm
unsigned short fifoReplace(short* refstring, size_t reflength, short *buffer, size_t buflength) {
	printf("\n**** FIFO REPLACEMENT ****\n");

	short buf_front=-1;		// Buffer index of recently filled page
	short in_ref;			// Store incoming reference
	unsigned short page_faults=0;	// No. of page faults

	for(size_t i=0,j; i<reflength; ++i) {

		in_ref=refstring[i];
		printf("\nIncoming page reference: %hi",in_ref);

		// Check if incoming reference is already present
		for(j=0; j<buflength; ++j)
			if(buffer[j]==in_ref) {
				printf("\n HIT: ");		// If yes, HIT
				break;
			}

		if(j==buflength) {
			printf("\nMISS: ");			// If no, MISS

			// If MISS, replace the oldest one to go in, and increment page fault
			buffer[++buf_front % buflength] = in_ref;
			++page_faults;
		}

		// Print buffer state
		displayPages(buffer,buflength);

		// If HIT, ignore and go to next reference

	}
	printf("\n**************************\n\n");
	return page_faults;
}

// LRU Replacement algorithm
unsigned short lruReplace(short* refstring, size_t reflength, short *buffer, size_t buflength) {
	printf("\n**** LRU REPLACEMENT ****\n");

	short in_ref;			// Store incoming reference
	unsigned short page_faults=0;			// No. of page faults
	unsigned short usage_freq[buflength];	// Usage frequency of buffer references

	// Initially, all usage frequencies are zero
	for(size_t i=0,j; i<buflength; ++i)
		usage_freq[i]=0;

	for(size_t i=0,j,k; i<reflength; ++i) {

		in_ref=refstring[i];
		printf("\nIncoming page reference: %hi",in_ref);

		// Check if incoming reference is already present
		for(j=0; j<buflength; ++j)
			if(buffer[j]==in_ref) {
				printf("\n HIT: ");		// If yes, HIT
				break;
			}

		if(j==buflength) {
			printf("\nMISS: ");			// If no, MISS

			// Search for the element with lowest usage frequency from beginning (Jugaad 100)
			k=buflength;
			for(short freq=0; k==buflength && freq<=i; ++freq)
				for(k=0; k<buflength; k++)
					if(usage_freq[k]==freq) {	// Replace it
						buffer[k]=in_ref;
						j=k;
						++page_faults;			// And increment page fault
						break;
					}
		}

		// Increase usage frequency count by 1
		++usage_freq[j];

		// Print buffer state
		displayPages(buffer,buflength);

	}
	printf("\n*************************\n\n");
	return page_faults;
}

int main() {
	// Menu choice
	char x;
	printf("Select algorithm:\n\t1. FIFO\n\t2. LRU\nEnter choice: ");
	scanf("%c",&x);

	// Reference string, buffer frame size
	size_t l,s;
	printf("\nEnter length of reference string: ");
	scanf("%zu",&l);
	printf("Enter buffer frame size: ");
	scanf("%zu",&s);
	printf("\nEnter reference string:-\n");
	short refstring[l],buffer[s];
	for(size_t i=0; i<l; ++i) {
		printf("Enter reference string element %zu: ",i+1);
		scanf("%hi",&refstring[i]);
	}

	// Initially buffer is empty
	for(size_t i=0; i<s; ++i)
		buffer[i]=-1;

	// Run choice and print no. of page faults
	switch(x) {
		case '1':
			printf("FIFO replacement page faults = %hu",
			fifoReplace(refstring,l,buffer,s));
			break;

		case '2':
			printf("LRU replacement page faults = %hu",
			lruReplace(refstring,l,buffer,s));
			break;

		default:
			printf("Eh? Wrong choice!");
			return 1;
	}

	printf("\n\nProgram ended.\n");
	return 0;
}
