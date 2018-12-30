/*
    This file is part of FISCO-BCOS.

    FISCO-BCOS is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    FISCO-BCOS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FISCO-BCOS.  If not, see <http://www.gnu.org/licenses/>.
*/
/** @file GmHash.cpp
 *  @author asherli
 *  @date 2018
 */

#include <libdevcore/SHA3.h>

#include "sm3/sm3.h"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
using namespace dev;

namespace dev {

// add SM3
bool sha3(bytesConstRef _input, bytesRef o_output) {
  if (o_output.size() != 32)
    return false;

  SM3((unsigned char *)_input.data(), _input.size(),
      (unsigned char *)o_output.data());
  return true;
}

bool keccak256(bytesConstRef _input, bytesRef o_output) {
  if (o_output.size() != 32)
		return false;
  SM3((unsigned char *)_input.data(), _input.size(), (unsigned char *)o_output.data());
  return true;
}

} // namespace dev
