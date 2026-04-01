import os
import requests
from bs4 import BeautifulSoup
import time

# 自分のAtCoder ID
USER = "sam_el"

def get_submissions():
    """AtCoder ProblemsのAPIから提出履歴を全件取得する"""
    submissions = []
    from_second = 0
    while True:
        url = f"https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions?user={USER}&from_second={from_second}"
        response = requests.get(url)
        if response.status_code != 200:
            print("APIの取得に失敗しました")
            break
        
        data = response.json()
        if not data:
            break
            
        submissions.extend(data)
        from_second = data[-1]['epoch_second'] + 1
        time.sleep(1) # APIサーバーへの負荷軽減
        
    return submissions

def get_code(contest_id, sub_id):
    """AtCoderの提出ページからソースコードをスクレイピングする"""
    url = f"https://atcoder.jp/contests/{contest_id}/submissions/{sub_id}"
    response = requests.get(url)
    soup = BeautifulSoup(response.text, "html.parser")
    pre = soup.find("pre", id="submission-code")
    return pre.text if pre else None

def get_extension(language):
    """言語名から拡張子を判定する"""
    lang = language.lower()
    if "c++" in lang or "cpp" in lang: return ".cpp"
    if "python" in lang or "pypy" in lang: return ".py"
    if "java" in lang: return ".java"
    if "rust" in lang: return ".rs"
    if "c#" in lang: return ".cs"
    return ".txt"

def main():
    print(f"--- {USER} の提出を取得開始 ---")
    submissions = get_submissions()
    submissions.sort(key=lambda x: x['epoch_second'])

    for sub in submissions:
        # AC（正解）以外の提出はスキップ
        if sub['result'] != 'AC':
            continue

        contest = sub['contest_id']
        problem = sub['problem_id']
        sub_id = sub['id']
        ext = get_extension(sub['language'])

        # 保存先のフォルダとファイル名を作成（例: abc300/abc300_a.cpp）
        os.makedirs(contest, exist_ok=True)
        file_path = os.path.join(contest, f"{problem}{ext}")

        # すでにダウンロード済みのファイルがあればスキップ
        if os.path.exists(file_path):
            continue

        print(f"取得中: {contest} / {problem}")
        code = get_code(contest, sub_id)
        
        if code:
            with open(file_path, "w", encoding="utf-8") as f:
                f.write(code)
            # 【超重要】AtCoderのサーバーを攻撃しないために1.5秒待機
            time.sleep(1.5)

    print("--- 取得完了！ ---")

if __name__ == "__main__":
    main()
