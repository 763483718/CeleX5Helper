#!/bin/expect
spawn scp -r ./src server@10.12.41.81:/home/server/Desktop/cgz/CeleX5Helper/
expect "password:"
send "vision\r"
interact

spawn scp -r ./include server@10.12.41.81:/home/server/Desktop/cgz/CeleX5Helper/
expect "password:"
send "vision\r"
interact

spawn scp -r ./src server@10.12.41.188:/home/server/Desktop/cgz/CeleX5Helper/
expect "password:"
send "vision\r"
interact

spawn scp -r ./include server@10.12.41.188:/home/server/Desktop/cgz/CeleX5Helper/
expect "password:"
send "vision\r"
interact

spawn scp ./CMakeLists.txt server@10.12.41.188:/home/server/Desktop/cgz/CeleX5Helper/
expect "password:"
send "vision\r"
interact

spawn scp ./CMakeLists.txt server@10.12.41.81:/home/server/Desktop/cgz/CeleX5Helper/
expect "password:"
send "vision\r"
interact