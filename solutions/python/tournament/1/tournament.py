def tally(rows):
    results = {}
    for row in rows:
        team1, team2, res = row.split(';')
        win1, draw1, loss1 = results.get(team1, (0,0,0))
        win2, draw2, loss2 = results.get(team2, (0,0,0))
        if res=='win':
            win1 += 1; loss2 += 1
        elif res=='loss':
            win2 += 1; loss1 += 1
        else:
            draw1 += 1; draw2 += 1
        results[team1] = win1, draw1, loss1
        results[team2] = win2, draw2, loss2
    report = [(team, win+draw+loss, win, draw, loss, win*3+draw) 
              for team, (win, draw, loss) in results.items()]
    report.sort(key=lambda record: record[0]) # by team name
    report.sort(key=lambda record: record[5], reverse=True) # by points desc
    print_report = [f"{team:31}|{played:3} |{win:3} |{draw:3} |{loss:3} |{points:3}" 
              for (team, played, win, draw, loss, points) in report]
    return ["Team                           | MP |  W |  D |  L |  P"] + print_report

