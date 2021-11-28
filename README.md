# Filtering ip package

Containse classes for Octat, Ipv4 address

Main idea of filtering is during load filter every line, if any octate is invalid I change it for 256 and if any octat in ip address is invalid, I change entire IPv4 address to 0.0.0.0
We know what this address mean ;-)

And before output ranged addresses I simple remove this one default address from set))
