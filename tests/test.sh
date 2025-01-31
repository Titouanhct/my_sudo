#!/bin/sh

make re
sudo chown root ./my_sudo
sudo chmod +s ./my_sudo
clear

echo "Résultat des tests fonctionnels pour my_sudo :\n"

./my_sudo id > test
sudo id > cmp
diff test cmp && echo "[TEST 01] : test for basic id is a success" || echo "[TEST 01] : test for basic id is a fail"

./my_sudo ls include/ > test
sudo ls include/ > cmp
diff test cmp && echo "[TEST 02] : test for basic ls is a success" || echo "[TEST 02] : test for basic ls is a fail"

sudo useradd testuser -g sudo -G daemon

./my_sudo -u testuser id > test
sudo -u testuser id > cmp
diff test cmp && echo "[TEST 03] : test for -u testuser id is a success" || echo "[TEST 03] : test for -u testuser id is a fail"

./my_sudo -u testuser -g daemon id > test
sudo -u testuser -g daemon id > cmp
diff test cmp && echo "[TEST 04] : test for -u testuser & -g daemon id is a success" || echo "[TEST 04] : test for -u testuser & -g daemon id is a fail"

./my_sudo whoami > test
sudo whoami > cmp
diff test cmp && echo "[TEST 05] : test for whoami is a success" || echo "[TEST 05] : test for whoami is a fail"

./my_sudo cat /etc/shadow > test
sudo cat /etc/shadow > cmp
diff test cmp && echo "[TEST 06] : test for accessing /etc/shadow is a success" || echo "[TEST 06] : test for accessing /etc/shadow is a fail"

./my_sudo echo "Hello from my_sudo" > test
sudo echo "Hello from my_sudo" > cmp
diff test cmp && echo "[TEST 07] : test for echo command is a success" || echo "[TEST 07] : test for echo command is a fail"

echo "testuser:NewPass123" | ./my_sudo chpasswd > test
echo "testuser:NewPass123" | sudo chpasswd > cmp
diff test cmp && echo "[TEST 08] : test for chpasswd is a success" || echo "[TEST 08] : test for chpasswd is a fail"

sudo userdel testuser
rm test cmp