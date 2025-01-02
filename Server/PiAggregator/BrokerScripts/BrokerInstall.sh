# add init user and pass, this can be used for all modules and serer user/pass
PASSWD_FILE="/etc/mosquitto/passwd"
NEW_ACL_FILE="acl_file"
ACL_FILE="/etc/mosquitto/acl_file"

set -e

echo "Test"

# install mosquitto
sudo apt-get install -y mosquitto mosquitto-clients

# configure mosquitto, listener set to port 1883
grep -qxF 'listener 1883' /etc/mosquitto/mosquitto.conf || echo 'listener 1883' | sudo tee -a /etc/mosquitto/mosquitto.conf > /dev/null

# require user to access broker
grep -qxF 'allow_anonymous false' /etc/mosquitto/mosquitto.conf || echo 'allow_anonymous false' | sudo tee -a /etc/mosquitto/mosquitto.conf > /dev/null

sudo sed -i '/^allow_anonymous true$/c\allow_anonymous false' /etc/mosquitto/mosquitto.conf

# copy acl_file with permissions
if [[ -f "$ACL_FILE" ]]; then
    echo "Backing up the old ACL..."
    sudo cp "$ACL_FILE" "${ACL_FILE}.backup"
fi
sudo cp -f "$NEW_ACL_FILE" "$ACL_FILE"

#add user to file
# check if password file exists
if [ ! -f "$PASSWD_FILE" ]; then
  sudo touch "$PASSWD_FILE"
  echo "$PASSWD_FILE created."
else
  echo "File already exists."
fi


# TO ADD USER do ->
# $ sudo mosquitto_passwd /etc/mosquitto/passwd <user_name>