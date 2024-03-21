#!/bin/sh

# Power menu script using tofi

CHOSEN=$(printf "Reboot\nShutdown\n" | rofi -dmenu -i -theme-str 'prompt { enabled: false; }')
case "$CHOSEN" in
"Reboot") reboot ;;
"Shutdown") poweroff ;;
*) exit 1 ;;
esac
