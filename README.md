# xorcrypter-linux
Simple XOR encryption for files on Linux.

Encrypts each byte of the file with a byte of the key. 0's are ignored since many binaries contain long sequences of 0x00 bytes which would reveal the key. 

# Usage
Encrypts a file ```nc``` with key ```superswan```
```./xorcrypt nc superswan nc_enc```
