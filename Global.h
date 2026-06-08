#pragma once
#include <iostream>
#include "clsUser.h"

inline clsUser CurrentUser = clsUser::Find("", "");
inline int Trials = 3;