import os
import sys

def remove_blank_lines_from_file(file_path):
    try:
        with open(file_path, 'r', encoding='utf-8') as f:
            lines = f.readlines()
        
        # 빈 줄이 아닌 줄만 남기고, 연속된 빈 줄은 한 줄로 줄임
        new_lines = []
        prev_blank = False
        for line in lines:
            if line.strip() == '':
                if not prev_blank:
                    new_lines.append('\n')  # 빈 줄 하나만 유지
                prev_blank = True
            else:
                new_lines.append(line)
                prev_blank = False
        
        # 파일의 처음과 끝에 있는 빈 줄 제거
        while new_lines and new_lines[0].strip() == '':
            new_lines.pop(0)
        while new_lines and new_lines[-1].strip() == '':
            new_lines.pop()
        
        with open(file_path, 'w', encoding='utf-8') as f:
            f.writelines(new_lines)
        print(f"정리 완료: {file_path}")
    except Exception as e:
        print(f"오류 발생: {file_path} - {str(e)}")

def process_directory(directory):
    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith('.c'):
                file_path = os.path.join(root, file)
                remove_blank_lines_from_file(file_path)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("사용법: python remove_blank_lines.py <폴더경로>")
        sys.exit(1)
    
    directory = sys.argv[1]
    if not os.path.isdir(directory):
        print(f"오류: {directory}는 유효한 디렉토리가 아닙니다.")
        sys.exit(1)
    process_directory(directory) 