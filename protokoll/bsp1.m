% b,a sind die Koeffizienten fuer den Filter
% steps gibt an wieviele Simulationsschritte 
% gemacht werden, wird benoetigt
% um Liste zu initialisieren
% soll und ist werden uebergeben
function stell = PID(ist,soll,b,a,steps) %#eml
    persistent X
    
    eml.varsize('X',[1 steps+1]);
    
    % Differenz zwischen Soll und Ist Ausrechnen
    diff = soll-ist;
    diff = diff/0.0338;
    
    % Am Anfang die History initialisieren
    if isempty(X)
        X = diff;
    % neue Werte hinzufügen
    else
        X = [X diff];
    end;
    
    res = filter(b,a,X);
    
    % letztes Ergebnis des Filters ausgeben
    % auf 10 limitieren
    stell = min(res(end),10);