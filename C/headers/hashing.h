unsigned int find_prime_file(unsigned int size, char* filename);
unsigned int set_r(int key, unsigned int m);
void changebase(int key, unsigned int m, unsigned int *K, unsigned int r);
unsigned int* generate_hash(unsigned int m,  unsigned int r);
unsigned int dotproduct(unsigned int* A, unsigned int* B, const unsigned int r);
unsigned int hash(unsigned int* K, unsigned int* A, const unsigned int r, int m);

