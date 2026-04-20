#include "cListCandidate.h"
#include <algorithm>

cListCandidate::cListCandidate() {}

void cListCandidate::Input() {
    int n;
    cout << "Nhap so luong thi sinh: ";
    cin >> n;
    
    candidates.resize(n);
    for (int i = 0; i < n; ++i) {
        cout << "\n--- Nhap thong tin thi sinh thu " << i + 1 << " ---" << endl;
        candidates[i].Input();
    }
}

void cListCandidate::OutputAbove15() const {
    cout << "\n--- Danh sach thi sinh co tong diem > 15 ---" << endl;
    bool found = false;
    for (const auto& candidate : candidates) {
        if (candidate.GetTotalScore() > 15) {
            candidate.Output();
            found = true;
        }
    }
    if (!found) {
        cout << "Khong co thi sinh nao co tong diem > 15." << endl;
    }
}

void cListCandidate::OutputHighestScore() const {
    if (candidates.empty()) {
        cout << "Danh sach rong." << endl;
        return;
    }

    float maxScore = candidates[0].GetTotalScore();
    for (const auto& candidate : candidates) {
        if (candidate.GetTotalScore() > maxScore) {
            maxScore = candidate.GetTotalScore();
        }
    }

    cout << "\n--- Danh sach thi sinh co tong diem cao nhat (" << maxScore << ") ---" << endl;
    for (const auto& candidate : candidates) {
        if (candidate.GetTotalScore() == maxScore) {
            candidate.Output();
        }
    }
}

void cListCandidate::SortDescending() {
    sort(candidates.begin(), candidates.end(), [](const cCandidate& a, const cCandidate& b) {
        return a.GetTotalScore() > b.GetTotalScore();
    });
}

void cListCandidate::OutputAll() const {
    cout << "\n--- Danh sach tat ca thi sinh ---" << endl;
    for (const auto& candidate : candidates) {
        candidate.Output();
    }
}
