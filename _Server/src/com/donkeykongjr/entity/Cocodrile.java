package com.donkeykongjr.entity;

public class Cocodrile {

    private Integer iD;
    public Integer iPos,jPos;
    public Integer onScreen, onField, onVine;
    public Integer cocoSpeed,mouth, whichCoco;
    public Integer viewU,viewD,viewR,viewL;

    public Cocodrile(){
        this.iD = 1;
    }

    public Integer getiD(){
        return this.iD;
    }

}
