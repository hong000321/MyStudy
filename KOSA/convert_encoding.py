import os
import sys

def convert_file_encoding(file_path):
    try:
        # EUC-KR로 인코딩된 파일을 읽기
        with open(file_path, 'rb') as f:
            content = f.read()
        
        # EUC-KR에서 디코딩
        decoded_content = content.decode('euc-kr')
        
        # UTF-8로 인코딩하여 같은 파일에 저장
        with open(file_path, 'w', encoding='utf-8') as f:
            f.write(decoded_content)
            
        print(f"변환 완료: {file_path} (EUC-KR -> UTF-8)")
        return True
        
    except UnicodeDecodeError:
        print(f"오류: {file_path} 파일이 EUC-KR 인코딩이 아닐 수 있습니다.")
        return False
    except Exception as e:
        print(f"오류 발생: {str(e)}")
        return False

def process_directory(directory):
    success_count = 0
    fail_count = 0
    
    # 디렉토리 내의 모든 파일과 하위 디렉토리를 순회
    for root, dirs, files in os.walk(directory):
        for file in files:
            file_path = os.path.join(root, file)
            if convert_file_encoding(file_path):
                success_count += 1
            else:
                fail_count += 1
    
    print(f"\n변환 완료: 성공 {success_count}개, 실패 {fail_count}개")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("사용법: python convert_encoding.py <폴더경로>")
        sys.exit(1)
    
    directory = sys.argv[1]
    if not os.path.isdir(directory):
        print(f"오류: {directory}는 유효한 디렉토리가 아닙니다.")
        sys.exit(1)
        
    process_directory(directory) 