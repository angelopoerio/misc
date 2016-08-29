'''
   roman 2 decimal!
   Author: Angelo Poerio
'''

def roman2dec(roman):
	symbols = {'I': 1,
                   'V': 5,
                   'X': 10,
                   'L': 50,
                   'C': 100,
                   'D': 500,
                   'M': 1000}
        dec = 0
        for i, d in enumerate(roman):
          try:
            dec += symbols[d] if symbols[d] >= symbols[roman[i+1]] else -1 * symbols[d]
          except IndexError:
            dec += symbols[d]
          except KeyError:
            raise Exception('not a valid roman number')
        return dec

assert roman2dec("XXXVI") == 36
assert roman2dec("MMMCCXLIII") == 3243
assert roman2dec('CMXXXI') == 931       
