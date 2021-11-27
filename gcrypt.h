/*
 * gcrypt.h - RSA encryption, decryption, and key generation
 * 
 *     Copyright (C) 2021  Roxanne MacKinnon
 * 
 *     This program is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 * 
 *     You should have received a copy of the GNU General Public License
 *     along with this program.  If not, see <https://www.gnu.org/licenses/>.#ifndef __GCRYPT_H__
 *
 *     <rdm3@williams.edu> Roxanne MacKinnon
 */
#define __GCRYPT_H__

#include <stdint.h>

/**
 * struct that can represent both a public keypair (n,e)
 * or private keypair (n,d)
 */
typedef struct GCryptKey {
  uint64_t exponent;
  uint64_t modulus;
} GCryptKey;


/**
 * Randomly generate a public/private keypair, placing the results in
 * the given pointer arguments.
 */
void gcrypt_generate_keypair(GCryptKey * public_key, GCryptKey * private_key);

/**
 * Encrypt a message using the RSA encryption scheme.
 * message: a plaintext string message to be encrypted
 * key: a GCryptKey struct used to one-way encrypt the message
 * Returns a dynamically allocated encryption of the given message.
 */
char * gcrypt_encrypt(char * message, GCryptKey key);

/**
 * Decrypt a received message using the RSA scheme.
 * message: a message encrypted using the receiver's public key
 * key: the receiver's private key, not known to the sender
 * Returns a dynamically allocated string representing the original message.
 */
char * gcrypt_decrypt(char * message, GCryptKey key);

#endif
