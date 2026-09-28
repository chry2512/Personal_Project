import hashlib
import time

def calculate_proof_of_work(student_id, difficulty, nonce):
    
    prefix = '0' * difficulty
    print(f"Prefix per la difficoltà {difficulty}: {prefix}")
    start_time = time.time()
    
    while True:
       
        data = f"{student_id}{nonce}".encode()
        hash_result = hashlib.sha256(data).hexdigest()
        
        if hash_result.startswith(prefix):
            end_time = time.time()
            return nonce, hash_result, end_time - start_time
        
        nonce += 1

def main():
    student_id = "0082300516" 
    difficulties = [4, 5, 6]  
   
    
    for difficulty in difficulties:
        nonce = 0
        print(f"Calcolo per difficulty: {difficulty} zeri iniziali")
        nonce, hash_result, elapsed_time = calculate_proof_of_work(student_id, difficulty, nonce)
        print(f"Nonce trovato: {nonce}")
        print(f"Hash risultante: {hash_result}")
        print(f"Tempo impiegato: {elapsed_time:.2f} secondi\n")

if __name__ == "__main__":
    main()