#include "utils.h"

bool Utils::is_integer(String check_val) {
    for (int i = 0; i < check_val.length(); i++) {
        if (!isDigit(check_val.charAt(i))) {
            return false;
        }
    }
    return true;
}
