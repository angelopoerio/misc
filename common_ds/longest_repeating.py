import sys

# Out the character of the longest repeating sequence in a string
# Ex: "aaabb" -> "a"
#      "kkllccc" -> "c"
# Complexity: O(n)
# Author: Angelo Poerio <angelo.poerio@gmail.com>

def longest_repeating(in_str):
  curr_sub = in_str[0]
  longest_sub_so_far = in_str[0]
  longest_len_so_far = 1
  current_len = 1

  for current_ch in in_str[1:]:
    if current_ch == curr_sub:
      current_len += 1
    else:
      if current_len > longest_len_so_far: 
        longest_len_so_far = current_len
        longest_sub_so_far = curr_sub
      curr_sub = current_ch
      current_len = 1
  
  return longest_sub_so_far if current_len < longest_len_so_far else curr_sub
      
if __name__ == "__main__":
  for i_str in sys.argv[1:]:
    print "{0} - longest sub: {1}".format(i_str, longest_repeating(i_str))
