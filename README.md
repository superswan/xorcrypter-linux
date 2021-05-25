# xorcrypter-linux
Simple XOR encryption for files on Linux.

Encrypts each byte of the file with a byte of the key. 0's are ignored since many binaries contain long sequences of 0x00 bytes which would reveal the key. 

# Usage
Encrypts a file ```nc``` with key ```superswan```
<br>
```./xorcrypt nc superswan nc_enc```
<br>
The file can be decrypted by running the program against the encrypted file using the correct key.
<br>
```./xorcrypt nc_enc superswan nc_dec```

