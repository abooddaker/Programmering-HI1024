library ieee;
use ieee.std_logic_1164.all;

entity eqcomp is
port(insignal :in std_logic_vector(2 downto 0);
    a,b,c,d,e,f,g:out std_logic);
end eqcomp;

architecture behavior of eqcomp is
begin 
comp: process(insignal)
    begin
    a <= '1';
    b <= '1';
    c <= '1';
    d <= '1';
    e <= '1';
    f <= '1';
    g <= '1';

    if insignal = "001" then 
    a <= '0';
    elseif insignal = "010" then
    a <= '0';
    b <= '0';
    elseif insignal = "011" then
    a <= '0';
    b <= '0';
    c <= '0';
    elseif insignal = "100" then
    a <= '0';
    b <= '0';
    c <= '0';
    d <= '0';
    