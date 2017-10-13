#include <iostream>
#include "ChainingHash.h"

int main()
{
  ChainHash CH(5);

  CH.setCH( (char*)"radish", (char*)"pepper");
  CH.setCH( (char*)"pumpkin", (char*)"marrow");
  CH.setCH( (char*)"tomato", (char*)"potato");
  CH.setCH( (char*)"pea", (char*)"onion");

  CH.getCH((char*)"tomato");
  CH.getCH((char*)"radish");
  CH.getCH((char*)"pea");
  CH.getCH((char*)"cucumber");

  return 1;
}
