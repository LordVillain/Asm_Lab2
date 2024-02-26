//task#1//

#include <iostream>
int main()
{
    int x;
    int result1;

    std::cin >> x;
    if(x == 0)
    {
        std::cout << "not correct x" << std::endl;
        return 0;
    }
    _asm 
    {
        mov eax, x
        add eax, x
        sub eax, 1

        mov ecx, x
        add ecx, x
        add ecx, 1

        imul eax, ecx

        mov ecx, x
        add ecx, 3

        imul eax, ecx

        mov ebx, x
        add ebx, x
        cdq
        idiv ebx
        mov result1, eax
    }

    int result2 = (2 * x - 1) * (2 * x + 1) * (x + 3) / (2 * x);

    if (result1 == result2)
        std::cout << "Result (assembly): " << result1 << " == " << "Result (C++): " << result2;
    if (result1 != result2)
        std::cout << "Result (assembly): " << result1 << " != " << "Result (C++): " << result2 << " :/";

}



//task#2//

#include <iostream>

bool isPalindrome(int number) {
    bool result;

    _asm 
    {
        mov eax, number
        mov ebx, 0
        mov ecx, 10

        reverse_loop:
        xor edx, edx     
        div ecx
        imul ebx, 10
        add ebx, edx
        test eax, eax
        jnz reverse_loop

        cmp ebx, number
        sete result
    }

    return result;
}

int main() {
    int number;

    std::cout << "Enter a number: ";
    std::cin >> number;

    if (isPalindrome(number)) {
        std::cout << number << " is a simmetrik" << std::endl;
    }
    else {
        std::cout << number << " is not a simmetrik" << std::endl;
    }

    return 0;
}