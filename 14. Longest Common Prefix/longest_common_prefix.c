#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longest_common_prefix(char **strs, int strsSize) {
  if (strsSize <= 0) {
    return "";
  } else if (strsSize == 1) {
    return strs[0];
  }
  char *tmp_str = strs[0];
  int base = strlen(tmp_str);
  int base_index = -1;
  for (int i = 1; i < strsSize;) {
    int tmp = strlen(strs[i]);
    if (tmp > 0) {
      int tmp_index = -1;
      int len = tmp > base ? base : tmp;
      for (int j = 0; j < len; j++) {
        if (tmp_str[j] == strs[i][j]) {
          tmp_index = j;
        } else {
          tmp_str[j] = '\0';
          break;
        }
      }

      if (tmp_index > -1) {
        if (base_index == -1 || tmp_index < base_index) {
          for (int k = 0; k < base; k++) {
            if (tmp_index >= k) {
              tmp_str[k] = strs[i][k];
            } else {
              tmp_str[k] = '\0';
              break;
            }
          }
          base_index = tmp_index;
        }
      } else {
        break;
      }
      i++;
    } else {
      return "";
    }
  }
  return tmp_str;
}

/**
 * ["flower","flow","flight"]
 * ["c","c","c"]
 * ["dog","racecar","car"]
 * ["flower","flowers","flot","flower"]
 * ["bb","b"]
 * []
 *
 */
int main() {
  char **test_source = (char **)malloc(sizeof(char *) * 3);
  char **test_source1 = (char **)malloc(sizeof(char *) * 3);
  char **test_source2 = (char **)malloc(sizeof(char *) * 4);
  char **test_source3 = (char **)malloc(sizeof(char *) * 3);
  char **test_source4 = (char **)malloc(sizeof(char *) * 3);

  for (int i = 0; i < 4; i++) {
    if (i < 3) {
      test_source[i] = (char *)malloc(50 * sizeof(char));
      test_source1[i] = (char *)malloc(50 * sizeof(char));
      test_source3[i] = (char *)malloc(50 * sizeof(char));
      if (i < 2) {
        test_source4[i] = (char *)malloc(50 * sizeof(char));
      }
    }
    test_source2[i] = (char *)malloc(50 * sizeof(char));
  }
  // assign them all something
  sprintf(test_source[0], "flower");
  sprintf(test_source[1], "flow");
  sprintf(test_source[2], "flight");
  sprintf(test_source1[0], "c");
  sprintf(test_source1[1], "c");
  sprintf(test_source1[2], "c");
  sprintf(test_source2[0], "flower");
  sprintf(test_source2[1], "flowers");
  sprintf(test_source2[2], "flot");
  sprintf(test_source2[3], "flower");
  sprintf(test_source3[0], "dog");
  sprintf(test_source3[1], "racecar");
  sprintf(test_source3[2], "car");
  sprintf(test_source4[0], "bb");
  sprintf(test_source4[1], "b");

  printf("first test result: %s \n",
         longest_common_prefix((char **)test_source, 3));
  printf("second test result: %s\n",
         longest_common_prefix((char **)test_source1, 3));
  printf("third test result: %s\n",
         longest_common_prefix((char **)test_source2, 4));
  printf("fourth test result: %s\n",
         longest_common_prefix((char **)test_source3, 3));
  printf("fifth test result: %s\n",
         longest_common_prefix((char **)test_source4, 2));
  printf("sixth test result: %s\n",
         longest_common_prefix((char **)test_source1, 0));
  return 0;
}
