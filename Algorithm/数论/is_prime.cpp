//
// Created by fate on 2019/3/31.
//

//如何快速判断一个数是否为素数：
bool is_prime(int num) {
    if(num <= 1) {
        return false;
    }
    if(num == 2 || num == 3) {
        return true;
    }
    if(num % 6 != 1 && num % 6 != 5) {
        return false;
    }
    int temp = sqrt(num);
    for(int i = 5; i <= temp; i += 6) {
        if(num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}