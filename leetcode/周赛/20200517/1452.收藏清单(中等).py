class Solution:
    def peopleIndexes(self, favoriteCompanies: List[List[str]]) -> List[int]:
        fav = []
        for x in favoriteCompanies:
            s = set()
            for company in x:
                s.add(company)
            fav.append(s)
        ans = []
        N = len(fav)
        for i in range(N):
            flag = True
            for j in range(N):
                if i==j:
                    continue
                if fav[i].issubset(fav[j]):
                    flag = False
                    break
            if flag:
                ans.append(i)
        return ans
