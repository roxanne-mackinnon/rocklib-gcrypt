### GCRYPT.H
#### RSA encryption/decryption and key generation routines

RSA is a cryptographic system based on algebraic properties of prime numbers. In particular, it relies on the fact that if n is the product of two large primes, say p and q, finding p and q is computationally infeasible.

RSA is an asymmetric scheme, meaning that a party may send encrypted messages to the receiver, without being able to decrypt messages sent to that same receiver by other parties. The receiver alone has the ability to decrypt messages sent.

This is achieved through the use of public and private keys. In fact, suppose Alice wishes to send a message to Bob.
First, Alice encodes her message as a (probably large) number M.
Then, Alice takes Bob's public key (n,e) and calculates M^e (mod n), the exponent e of M modulo n.
Then, Alice sends this resulting number to Bob.

When bob receives the encrypted message M', he retreives the original message by calculating M' ^ d (mod n). This result is thanks to the findings of abstract algebra with respect to prime numbers.

This library provides routines for generating public and private keys (e,n) and (d,n), and routines for encrypting and decrypting messages according to those keys.