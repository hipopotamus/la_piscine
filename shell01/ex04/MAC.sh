ifconfig -a | grep 'ether' | sed -e 's/^[\t]*//g' | tr -d ''
