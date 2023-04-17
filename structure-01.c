typedef struct {
    int weight;
    int height;
} WeightAndHeight;

typedef int KEY; // We put it here because to put an alias to primitive type int

#define MAX_HEIGHT 225

int main() {
    WeightAndHeight person1;
    person1.weight = 56;
    person1.height = 185;
    
    printf("Weight: %i, Height: %i. ", person1.weight, person1.height);
    
    if (person1.height > MAX_HEIGHT) printf("Height above the maximum height.");
    else printf("Height under the maximum height.");

    return 0;
}