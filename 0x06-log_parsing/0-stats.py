#!/usr/bin/python3
import fileinput

file_size = 0

stat_code = {"200": 0, "301":0, "400":0, "401":0, "403":0, "404":0, "405":0, "500":0}
counter = 0

for line in fileinput.input():
    line_split = line.split()
    file_size = file_size + int(line_split[8])
    stat_code[line_split[7]] = stat_code[line_split[7]] + 1
    counter += 1
    if counter == 9:
        counter = 0
        print('File size: {}\n200: {}\n401: {}\n403: {}\n404: {}\n405: {}\n500: {}'.format(file_size, stat_code['200'],
            stat_code['401'],
            stat_code['403'],
            stat_code['404'],
            stat_code['405'],
            stat_code['500']))