#!/usr/bin/awk -f
BEGIN{
}
length($0) >= MIN && length($0) <= MAX{
        print toupper($0)
    }
length($0) < MIN || length($0) >= MAX{
        print $0
    }
