#include <iostream>
#include <climits>

//function declaration
#ifndef MARMOSET_TESTING
int main();
#endif
unsigned int add_checksum(unsigned int n);
void add_checksum (unsigned int array [], std::size_t capacity);
bool verify_checksum(unsigned int n);
unsigned int remove_checksum(unsigned int n);
void remove_checksum ( unsigned int array[], std::size_t capacity );


unsigned int protected_value{};




//function definition
#ifndef MARMOSET_TESTING
int main() {
	unsigned int value_to_protect{21352411};

    unsigned int protected_value = add_checksum(value_to_protect);
    std::cout << "The value " << value_to_protect
        << " with the checksum added is " << protected_value
        << "." << std::endl;
    
    if (verify_checksum(protected_value))
    {
        std::cout << "The checksum is valid." << std::endl;
    }
    else   {
        std::cout << "The checksum is invalid." << std::endl;
    } 
    const std::size_t QTY_VALUES {3};
    unsigned int value_series[QTY_VALUES] {20201122, 20209913, 20224012};
    
    add_checksum(value_series, QTY_VALUES);
    
    std::cout << "Series with checksums added: ";
    for (std::size_t series_index {0};
        series_index < QTY_VALUES; series_index++)
    {
        std::cout << value_series[series_index] << " ";
    }

    std::cout << std::endl;
    
    return 0;
}   
#endif

unsigned int add_checksum(unsigned int n){

    if (0 < n < 99999999){
        int digit_1{};
        int digit_2{};
        int digit_3{};
        int digit_4{};
        int digit_5{};
        int digit_6{};
        int digit_7{};
        int digit_8{};
        int step_2{};
        int step_3{};
        int checksum{};



        digit_1 = n % 10;
        digit_2 = n / 10 % 10;
        digit_3 = n / 100 % 10;
        digit_4 = n / 1000 % 10;
        digit_5 = n / 10000 % 10; 
        digit_6 = n / 100000 % 10;
        digit_7 = n / 1000000 % 10;
        digit_8 = n / 10000000 % 10;

        digit_1*=2; //1
        digit_3*=2; //4
        digit_5*=2; //5
        digit_7*=2; //1

        if (digit_1 > 9||digit_3 > 9||digit_5 > 9||digit_7 > 9){
            digit_1 = (digit_1 / 10 % 10) + (digit_1 % 10);
            digit_3 = (digit_3 / 10 % 10) + (digit_3 % 10);
            digit_5 = (digit_5 / 10 % 10) + (digit_5 % 10);
            digit_7 = (digit_7 / 10 % 10) + (digit_7 % 10);
        }

        step_2 = digit_1 + digit_2 + digit_3 + digit_4 + digit_5 + digit_6 + digit_7 + digit_8;

        step_3 = step_2*9;

        checksum = step_3 % 10;
        
        protected_value = n * 10 + checksum;
    

       
    } else {
        protected_value = UINT_MAX;
       
    }
    return protected_value;
}

void add_checksum (unsigned int array [], std::size_t capacity){

    for (int i{}; i < capacity; ++i){
        array[i] = add_checksum(array[i]);
    }




}


bool verify_checksum(unsigned int n){
    int temp{};

    temp = ( protected_value - (protected_value%10))/10;

    temp = add_checksum(temp);

    if (temp == protected_value && protected_value < 999999999 ){
        return true;
    } else {
        return false;
    }

}

unsigned int remove_checksum(unsigned int n){
    int invalid{};
    if (verify_checksum(protected_value) == false || protected_value > 999999999){
        invalid = UINT_MAX;

        return invalid;

    } else {

        return (protected_value - (protected_value%10))/10;

    }
}


void remove_checksum ( unsigned int array[], std::size_t capacity ){

    for(int i{}; i < capacity; ++i){
        if (verify_checksum(protected_value) == false || protected_value > 999999999){
        array[i] = UINT_MAX;

        
    } else {

        array[i] = (protected_value - (protected_value%10))/10;

    }
}
    }
