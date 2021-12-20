# impor DES3 untuk Enkripsi dan md5 untuk kunci
from Crypto.Cipher import DES3
from hashlib import md5

# pada bagian ini memilih operasi ke satu atau ke dua
while True:
    print('Choose operation to be done:\n\t1- Encryption\n\t2- Decryption')
    operation = input('Your Choice: ')
    if operation not in ['1', '2']:
        break
        
    # operasi pada gambar atau file path
    file_path = input('File path: ')
    
    # kunci untuk Triple DES algorithm
    key = input('TDES key: ')

    # Encode kunci yang diberikan ke kunci ascii dengan operasi md5
    key_hash = md5(key.encode('ascii')).digest()

    # Sesuaikan kunci dari Hash Key yang dihasilkan untuk Final Triple DES Key
    tdes_key = DES3.adjust_key_parity(key_hash)
    
   #pada bagian ini kunci Triple DES, MODE_EAX untuk merahasiakan yang dapat menghasilkan nomor acak
    cipher = DES3.new(tdes_key, DES3.MODE_EAX, nonce=b'0')

    # membuaka file dari tempat yang ditempati file
    with open(file_path, 'rb') as input_file:
        file_bytes = input_file.read()
        
        if operation == '1':
            # melakukan enkripsi
            new_file_bytes = cipher.encrypt(file_bytes)
        else:
            # melakukan deskripsi
            new_file_bytes = cipher.decrypt(file_bytes)
    
    # Tulis nilai yang diperbarui dalam file dari tempat yang diberikan
    with open(file_path, 'wb') as output_file:
        output_file.write(new_file_bytes)
        print('Operation Done!')
        break